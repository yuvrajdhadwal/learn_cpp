/*
*
* Statistics about Modern Machines that I have learned from Classes!
*
* Instructions:
* 	- Clock Cycles complete every 0.33 ns (3 cycles per ns)
* 	- Realistic Processor Instructions Retired per Cycle: 1 - 3
* 	- Branch Misprediction Latency: ~15-20 cycles
* 	- Context Switch Latency: 10+ microseconds (due to clean TLB, cold caches)
*
* Memory:
* 	- Cache blocks are typically 64 bytes in size
* 	- L1d Size: 32 - 48 KB per Core (8-way set-associative)
* 	- L2 Size: 0.5 - 2 MB per Core
* 	- L3 Size: 32 - ~2 MB per core, shared across cores
* 	- Page Size: 4 KB, Huge Pages are 2 MB / 1 GB
* 	- L2 TLB - 2000 entries -> ~8 MB Process Working Set Size
*
* 	- L1 Cache Hit Load Latency: 2 cycles (TLB V2P Translation & Cache Lookup -> Tag Compare)
* 	- L2 Cache Hit Load Latency: ~4 ns
* 	- L3 Cache Hit Load Latency: ~15 ns
* 	- DRAM Hit Load Latency: ~100 ns
* 	- Disk Hit Load Latnecy: ~8 ms
* 	- Core-to-Core Cache Transfer: ~30-80 ns
* 	- NUMA Core-to-Core Transfer: ~100-200 ns
* 	- CXL Memory Load Latency: ~100 - 400 ns
*
* 	- 32 bit is -2.15 billion to 2.15 billion
*
* General things to Remember:
* 	- Cache Miss -> 100 ns -> 300 cycles -> 300-900 instructions stalled
* 	- Sequential Access faster than Random Access by 100x
* 	- Network is 1000x slower than DRAM
* 	- Kernel Bypass (eBPF) is 10x faster than Socket API
*
* Numbers are Averages/Medians, p99.9 is due to:
* 	- Page Faults
* 	- TLB Misses
* 	- Allocator Behavior
* 	- Interrupts, and handling
* 	- Lock contention
* 	- Cold cache
*/
