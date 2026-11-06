# Operating Systems Assignment 3 (CO3)

**Student:** Dharshini  
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
| Q1 Linking/loading | Task01/shared.c, Task01/main.c | See Task01/README.md |
| Q2 Paging | Task02/paging.c | `gcc -std=c11 -Wall -Wextra Task02/paging.c -o paging && ./paging` |
| Q3 Segmentation | Task03/segmentation.c | `gcc -std=c11 -Wall -Wextra Task03/segmentation.c -o segmentation && ./segmentation` |
| Q4 Demand paging | Task04/memory_touch.c | `gcc -std=c11 -Wall -Wextra Task04/memory_touch.c -o memory_touch && ./memory_touch 64` |
| Q5 Replacement | Task05/replacement.c | `gcc -std=c11 -Wall -Wextra Task05/replacement.c -o replacement && ./replacement` |
| Q6 Disk management | Task06/commands.md | Run Linux commands listed there |
| Q7 Memory plan | Task07/mlock_demo.c | `gcc -std=c11 -Wall -Wextra Task07/mlock_demo.c -o mlock_demo && sudo ./mlock_demo` |

**Important:** Run every task yourself on your Linux/WSL system, capture terminal screenshots and add measured results. Sample outputs and theoretical calculations in the report must be identified separately from your own measurements.
