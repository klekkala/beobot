getPort() {
    ports=() # Create array
    while IFS= read -r line # Read a line
    do
        NUM="$(echo "$line" | sed -n -e 's/.*\([0-9]\{4\}\).*/\1/p')"
        ports+=($NUM) # Append line to the array
    done < "$1"
}

getPort test.txt

while [ 1 ]
do
       for i in "${ports[@]}"
       do
               if [ ! -f "times/$i.txt" ];
               then
		       sleep 5.0
                       echo "restarting job $i"
                       #touch times/$i.txt
                       ps -aux | grep "port $i"
                       #ps -aux | grep "port $i" | awk {'print $2'} | xargs kill -9
                       #grep "$i" distribute/clients/$HOSTNAME.sh | tr -d '&' | exec awk '{print $0"--restart=True &"}' | /bin/bash
               fi
       done

done
