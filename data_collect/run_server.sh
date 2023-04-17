#Test script
#docker run -p 3000-3002:3000-3002 --gpus all carlasim/carla:0.9.9 ./CarlaUE4.sh /Game/Carla/Maps/Town07 -carla-server -fps=30 -name=3000 -world-port=3000
#./CarlaUE4.sh -carla-rpc-port=2129 -fps=30
#Server script for igpu10 spawning 20 processes


rm -rf $SYSLOGS/generator/ports/$HOSTNAME/*
#Listening

#Talking: write messages to $SYSLOGS/generator/msgs/servers folder and tfrecords to records/<iteration number>
#Listen: (a) Start server(s), (b) Kill server(s)
#Server script is starts from /lab/kiran/ mount point


#Prerequisites
#export PATH="/lab/kiran/anaconda3/bin:$PATH"
#cd vnewnnew_imitation/carracing/
#get list of files from the system folder
getPort() {
    ports=() # Create array
    while IFS= read -r line # Read a line
    do
    	NUM="$(echo "$line" | sed -n -e 's/.*\([0-9]\{4\}\).*/\1/p')"
        ports+=($NUM) # Append line to the array
    done < "$1"
}
getPort distribute/servers/$HOSTNAME.sh


for i in "${ports[@]}"; do
    echo "initializing"
    touch $SYSLOGS/generator/ports/$HOSTNAME/$i.txt
    echo 1 > $SYSLOGS/generator/ports/$HOSTNAME/$i.txt
done




echo "Starting server manager"
echo "Listening to text messages"
while [ 1 ];
do
	Y=$(< $SYSLOGS/generator/msgs/$HOSTNAME.msg)
	echo $Y
	if [ "$Y" -eq "1" ]
	then
		#start
		#start servers
		echo "tmux and docker services for starting carla"
		distribute/servers/$HOSTNAME.sh


		while [ "$Y" -eq "1" ]
		do
			#Check if single process wants to reset
			for i in "${ports[@]}"
			do
				X=$(< $SYSLOGS/generator/ports/$HOSTNAME/$i.txt)
				#Integer expression expected
				if [ "$X" -eq "2" ]
				then
					echo "restarting $i"
					D=$(docker ps -qf "name=$i")
					docker kill $D
					sleep 5.0
					#docker rm $(docker ps -a -f status=exited -q)
					grep "$i" distribute/servers/$HOSTNAME.sh | /bin/bash
					echo 1 > $SYSLOGS/generator/ports/$HOSTNAME/$i.txt
				fi
			done
			Y=$(< $SYSLOGS/generator/msgs/$HOSTNAME.msg)
		done

	elif [ "$Y" -eq "2" ]
	then
		#kill
		echo "restarting everything"
		docker kill $(docker ps -q)
		tmux kill-server
		docker rm $(docker ps -aq)

		echo 1 > $SYSLOGS/generator/msgs/$HOSTNAME.msg

	else
		#kill
		echo "stopping everything"
		docker kill $(docker ps -q)
		tmux kill-server
		docker rm $(docker ps -aq)

		while [ "$Y" -eq "0" ]
		do
			Y=$(< $SYSLOGS/generator/msgs/$HOSTNAME.msg)
		done
	fi
done
