tmux new-session -d docker run --rm --name=2213 -p 2213-2215:2213-2215 --gpus all $(grep "2213" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2393 -p 2393-2395:2393-2395 --gpus all $(grep "2393" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2084 -p 2084-2086:2084-2086 --gpus all $(grep "2084" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2090 -p 2090-2092:2090-2092 --gpus all $(grep "2090" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2051 -p 2051-2053:2051-2053 --gpus all $(grep "2051" distribute/sim.txt)

