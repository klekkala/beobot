tmux new-session -d docker run --rm --name=2306 -p 2306-2308:2306-2308 --gpus "device=0" $(grep "2306" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2309 -p 2309-2311:2309-2311 --gpus "device=0" $(grep "2309" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2312 -p 2312-2314:2312-2314 --gpus "device=0" $(grep "2312" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2315 -p 2315-2317:2315-2317 --gpus "device=0" $(grep "2315" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2318 -p 2318-2320:2318-2320 --gpus "device=0" $(grep "2318" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2321 -p 2321-2323:2321-2323 --gpus "device=0" $(grep "2321" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2324 -p 2324-2326:2324-2326 --gpus "device=0" $(grep "2324" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2327 -p 2327-2329:2327-2329 --gpus "device=0" $(grep "2327" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2330 -p 2330-2332:2330-2332 --gpus "device=1" $(grep "2330" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2336 -p 2336-2338:2336-2338 --gpus "device=1" $(grep "2336" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2339 -p 2339-2341:2339-2341 --gpus "device=1" $(grep "2339" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2342 -p 2342-2344:2342-2344 --gpus "device=1" $(grep "2342" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2345 -p 2345-2347:2345-2347 --gpus "device=1" $(grep "2345" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2348 -p 2348-2350:2348-2350 --gpus "device=1" $(grep "2348" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2351 -p 2351-2353:2351-2353 --gpus "device=1" $(grep "2351" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2354 -p 2354-2356:2354-2356 --gpus "device=1" $(grep "2354" distribute/sim.txt)

