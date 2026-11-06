#!/bin/sh
set -eu
cd "$(dirname "$0")"
printf '\n== Dynamic executable ==\n'
gcc -Wall -Wextra compare_linking.c -o dynamic_app
ls -lh dynamic_app
ldd dynamic_app || true
/usr/bin/time -f 'Elapsed: %e s | Max RSS: %M KB' ./dynamic_app
printf '\n== Static executable (if static libc is installed) ==\n'
if gcc -static compare_linking.c -o static_app 2>static_build.log; then
  ls -lh static_app
  /usr/bin/time -f 'Elapsed: %e s | Max RSS: %M KB' ./static_app
else
  echo 'Static build unavailable; see static_build.log (often static libc is not installed).'
fi
