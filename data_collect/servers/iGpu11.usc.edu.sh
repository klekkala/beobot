tmux new-session -d docker run --rm --name=2234 -p 2234-2236:2234-2236 --gpus "device=1" $(grep "2234" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2237 -p 2237-2239:2237-2239 --gpus "device=1" $(grep "2237" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2240 -p 2240-2242:2240-2242 --gpus "device=1" $(grep "2240" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2243 -p 2243-2245:2243-2245 --gpus "device=1" $(grep "2243" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2246 -p 2246-2248:2246-2248 --gpus "device=1" $(grep "2246" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2249 -p 2249-2251:2249-2251 --gpus "device=1" $(grep "2249" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2252 -p 2252-2254:2252-2254 --gpus "device=1" $(grep "2252" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2255 -p 2255-2257:2255-2257 --gpus "device=1" $(grep "2255" distribute/sim.txt)


