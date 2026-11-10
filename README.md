# Operating Systems Assignment 3 (CO3)

**Name:** Dharshini  
**Register Number:** 192521408  
**Repository:** https://github.com/CruDharshini/CSA04-192521408-Assignment3

## Environment
- Compiler: GCC (check with `gcc --version`)
- OS: Linux / Ubuntu / WSL (check with `lsb_release -a`)
- Compile C programs: `gcc -std=c11 -Wall -Wextra -O2 file.c -o program`
- Programs using pthreads: add `-pthread`; programs using `dlopen`: add `-ldl`.

## Task index and execution
| Task | Files | Run |
|---|---|---|
| Q1 Linking/loading | Task01/shared.c, Task01/main.c, compare_linking.c | See Task01/README.md and measure.sh |
| Q2 Paging | Task02/paging.c, fragmentation.c | Compile/run both programs |
| Q3 Segmentation | Task03/segmentation.c | `gcc -std=c11 -Wall -Wextra Task03/segmentation.c -o segmentation && ./segmentation` |
| Q4 Demand paging | Task04/memory_touch.c, cow_demo.c | See Task04/measure_faults.sh |
| Q5 Replacement | Task05/replacement.c, plot_faults.py | Compile/run; `python3 Task05/plot_faults.py` (requires matplotlib) |
| Q6 Disk management | Task06/commands.md, disk_evidence.sh | `sh Task06/disk_evidence.sh` (read-only; sudo may prompt) |
| Q7 Memory plan | Task07/mlock_demo.c, memory_plan_sim.py | See Task07/README.md |

**Important:** Run every task yourself on your Linux/WSL system, capture terminal screenshots and add measured results. Sample outputs and theoretical calculations in the report must be identified separately from your own measurements.
