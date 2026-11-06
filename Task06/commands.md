# Q6 — Disk management evidence

Run and screenshot:
```sh
lsblk -f
sudo fdisk -l
swapon --show
cat /proc/swaps
df -h
```

## Six 4-TB disks: usable capacity (decimal TB)
- RAID 0: 6 × 4 = 24 TB; no redundancy (one disk failure loses array).
- RAID 1 (six-way mirror): 4 TB usable; can survive up to five failures if one copy remains (implementation-dependent).
- RAID 5: (6−1) × 4 = 20 TB; survives one disk failure.
- RAID 10 (three mirrored pairs striped): 12 TB; can survive multiple failures provided no mirror pair loses both disks.
- RAID 6 alternative: (6−2) × 4 = 16 TB; survives any two disk failures.

For hospital records choose RAID 6 (or RAID 10 if performance/latency dominates), plus tested backups, monitoring and off-site copies. RAID is not a backup. Swap sizing depends on workload and whether hibernation is required; on a no-swap production server avoid relying on swap for capacity and monitor memory pressure. Discuss swap file vs partition: file is flexible/easier to resize; partition may offer simpler predictable setup.

Concepts: low-level formatting creates sectors; partitioning divides disk; logical formatting creates filesystem structures. Firmware loads boot code (boot block/EFI system partition), bootloader loads kernel/initramfs, kernel mounts root. Bad blocks are remapped by drive firmware or filesystem/OS tools; monitor SMART.
