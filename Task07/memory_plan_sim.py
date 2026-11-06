#!/usr/bin/env python3
"""Simple educational frame-allocation simulation (not an OS memory manager)."""
from collections import deque

frames=8
workloads={"Control":2,"ML":5,"Logging":1}
print(f"Available frames: {frames}")
for name,need in workloads.items():
    print(f"{name:8s}: requests {need} frame(s)")
print("Total planned frames:",sum(workloads.values()))
print("Remaining frames:",frames-sum(workloads.values()))
if sum(workloads.values())>frames:
    print("WARNING: overcommit; reduce ML allocation or defer non-critical work.")
else:
    print("Plan fits in simulated memory.")
print("Critical control memory should be preallocated/locked; this is only a planning model.")
