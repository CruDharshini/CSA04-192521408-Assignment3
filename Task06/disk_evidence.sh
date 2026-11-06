#!/bin/sh
# Read-only evidence collection. Does not partition, format, or modify disks.
set -u
for cmd in 'lsblk -f' 'df -h' 'swapon --show' 'cat /proc/swaps' 'sudo fdisk -l'; do
  echo "\n===== $cmd ====="; sh -c "$cmd" || echo "Command unavailable or permission denied: $cmd"
done
