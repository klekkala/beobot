

##Check
#WARNING THESE ARE NOT WORKING FOR SOME REASON!!!
tmux new-session -d docker run --rm --network=host --name=2072 -p 2072-2074:2072-2074 --gpus "device=1" carlasim/carla:0.9.9 ./CarlaUE4.sh /Game/Carla/Maps/Town07 -carla-server -fps=30 -world-port=2072
tmux new-session -d docker run --rm --network=host --name=2075 -p 2075-2077:2075-2077 --gpus "device=1" carlasim/carla:0.9.9 ./CarlaUE4.sh /Game/Carla/Maps/Town07 -carla-server -fps=30 -world-port=2075
tmux new-session -d docker run --rm --network=host --name=2030 -p 2030-2032:2030-2032 --gpus "device=0" carlasim/carla:0.9.9 ./CarlaUE4.sh /Game/Carla/Maps/Town07 -carla-server -fps=30 -world-port=2030
tmux new-session -d docker run --rm --network=host --name=2087 -p 2087-2089:2087-2089 --gpus all carlasim/carla:0.9.9 ./CarlaUE4.sh /Game/Carla/Maps/Town07 -carla-server -fps=30 -world-port=2087





#igpu11
tmux new-session -d docker run --rm --name=2207 -p 2207-2209:2207-2209 --gpus "device=0" $(grep "2207" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2210 -p 2210-2212:2210-2212 --gpus "device=0" $(grep "2210" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2216 -p 2216-2218:2216-2218 --gpus "device=0" $(grep "2216" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2219 -p 2219-2221:2219-2221 --gpus "device=0" $(grep "2219" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2222 -p 2222-2224:2222-2224 --gpus "device=0" $(grep "2222" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2225 -p 2225-2227:2225-2227 --gpus "device=0" $(grep "2225" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2228 -p 2228-2230:2228-2230 --gpus "device=0" $(grep "2228" distribute/sim.txt)

#igpu21
tmux new-session -d docker run --rm --name=2153 -p 2153-2155:2153-2155 --gpus "device=0" $(grep "2153" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2156 -p 2156-2158:2156-2158 --gpus "device=0" $(grep "2156" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2159 -p 2159-2161:2159-2161 --gpus "device=0" $(grep "2159" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2162 -p 2162-2164:2162-2164 --gpus "device=0" $(grep "2162" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2165 -p 2165-2167:2165-2167 --gpus "device=0" $(grep "2165" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2168 -p 2168-2170:2168-2170 --gpus "device=0" $(grep "2168" distribute/sim.txt)