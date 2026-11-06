# Q7 – Memory management design and experiment

## Run the programs
```sh
gcc -std=c11 -Wall -Wextra mlock_demo.c -o mlock_demo
sudo ./mlock_demo
python3 memory_plan_sim.py
```

The `mlock()` program requests locking 1 MiB. It may fail if the process has an insufficient `RLIMIT_MEMLOCK`; inspect `ulimit -l` and use appropriate system policy. Do not raise system limits blindly on shared/production machines.

The Python model is a conceptual allocation exercise only; it is not a kernel memory manager or a real-time guarantee. Record measured timings from your own system.
