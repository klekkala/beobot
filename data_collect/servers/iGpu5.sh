tmux new-session -d docker run --rm --name=2375 -p 2375-2377:2375-2377 --gpus all $(grep "2375" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2378 -p 2378-2380:2378-2380 --gpus all $(grep "2378" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2381 -p 2381-2383:2381-2383 --gpus all $(grep "2381" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2384 -p 2384-2386:2384-2386 --gpus all $(grep "2384" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2387 -p 2387-2389:2387-2389 --gpus all $(grep "2387" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2390 -p 2390-2392:2390-2392 --gpus all $(grep "2390" distribute/sim.txt)


