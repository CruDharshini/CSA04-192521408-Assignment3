# Q1 — Linking and loading

Build shared library and runtime loader:
```sh
gcc -fPIC -shared shared.c -o libshared.so
gcc -Wall -Wextra main.c -o runtime_loader -ldl
LD_LIBRARY_PATH=. ./runtime_loader
```
Static-vs-dynamic comparison (same source, library function): compile a static executable with `gcc main_static.c shared.c -static -o static_app` if static libc is installed; otherwise report that static libc is unavailable. Dynamic linking: `gcc main_static.c shared.c -o dynamic_app`. Compare `ls -lh`, `ldd dynamic_app`, `time ./dynamic_app`, `/usr/bin/time -v ./dynamic_app`, and `cat /proc/$PID/maps` while process is running. To demonstrate shared library update, rebuild libshared.so and rerun without relinking the loader. Missing library: temporarily rename it and capture dlopen error. For two instances, inspect their maps and explain shared file-backed pages (not all pages are shared; writable/private pages may be copy-on-write).
