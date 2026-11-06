#!/usr/bin/env python3
"""Plot FIFO/LRU/Optimal page-fault counts for 3 and 4 frames."""
import matplotlib.pyplot as plt
labels=['FIFO','LRU','Optimal']
counts3=[15,12,9]
counts4=[10,8,8]
x=range(len(labels)); width=.35
plt.bar([i-width/2 for i in x],counts3,width,label='3 frames')
plt.bar([i+width/2 for i in x],counts4,width,label='4 frames')
plt.xticks(list(x),labels);plt.ylabel('Page faults');plt.title('Page Replacement Comparison')
plt.legend();plt.tight_layout();plt.savefig('page_fault_comparison.png',dpi=160)
print('Saved page_fault_comparison.png')
