tmux new-session -d docker run --rm --name=2258 -p 2258-2260:2258-2260 --gpus "device=0" $(grep "2258" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2261 -p 2261-2263:2261-2263 --gpus "device=0" $(grep "2261" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2264 -p 2264-2266:2264-2266 --gpus "device=0" $(grep "2264" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2267 -p 2267-2269:2267-2269 --gpus "device=0" $(grep "2267" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2270 -p 2270-2272:2270-2272 --gpus "device=0" $(grep "2270" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2273 -p 2273-2275:2273-2275 --gpus "device=0" $(grep "2273" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2276 -p 2276-2278:2276-2278 --gpus "device=0" $(grep "2276" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2279 -p 2279-2281:2279-2281 --gpus "device=0" $(grep "2279" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2282 -p 2282-2284:2282-2284 --gpus "device=1" $(grep "2282" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2285 -p 2285-2287:2285-2287 --gpus "device=1" $(grep "2285" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2288 -p 2288-2290:2288-2290 --gpus "device=1" $(grep "2288" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2291 -p 2291-2293:2291-2293 --gpus "device=1" $(grep "2291" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2294 -p 2294-2296:2294-2296 --gpus "device=1" $(grep "2294" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2297 -p 2297-2299:2297-2299 --gpus "device=1" $(grep "2297" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2300 -p 2300-2302:2300-2302 --gpus "device=1" $(grep "2300" distribute/sim.txt)
tmux new-session -d docker run --rm --name=2303 -p 2303-2305:2303-2305 --gpus "device=1" $(grep "2303" distribute/sim.txt)
