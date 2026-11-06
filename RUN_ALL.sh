#!/bin/sh
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$ROOT"
printf '\n[Q2] Paging\n'; gcc -std=c11 -Wall -Wextra Task02/paging.c -o /tmp/a3_paging; /tmp/a3_paging
printf '\n[Q3] Segmentation\n'; gcc -std=c11 -Wall -Wextra Task03/segmentation.c -o /tmp/a3_seg; /tmp/a3_seg
printf '\n[Q5] Replacement\n'; gcc -std=c11 -Wall -Wextra Task05/replacement.c -o /tmp/a3_replace; /tmp/a3_replace
printf '\n[Q7] Memory planning\n'; python3 Task07/memory_plan_sim.py
printf '\nAll safe, non-privileged demos finished. Q1/Q4/Q6/Q7 mlock need their dedicated steps.\n'
