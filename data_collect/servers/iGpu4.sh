tmux new-session -d docker run --rm --name=2357 -p 2357-2359:2357-2359 --gpus all $(grep "2357" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2360 -p 2360-2362:2360-2362 --gpus all $(grep "2360" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2231 -p 2231-2233:2231-2233 --gpus all $(grep "2231" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2366 -p 2366-2368:2366-2368 --gpus all $(grep "2366" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2369 -p 2369-2371:2369-2371 --gpus all $(grep "2369" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2372 -p 2372-2374:2372-2374 --gpus all $(grep "2372" distribute/sim.txt)


