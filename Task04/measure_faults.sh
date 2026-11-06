#!/bin/sh
set -eu
cd "$(dirname "$0")"
gcc -O2 -Wall -Wextra memory_touch.c -o memory_touch
gcc -O2 -Wall -Wextra cow_demo.c -o cow_demo
printf '== Memory touch (64 MB) ==\n'; /usr/bin/time -v ./memory_touch 64
printf '\n== Copy-on-write ==\n'; ./cow_demo
