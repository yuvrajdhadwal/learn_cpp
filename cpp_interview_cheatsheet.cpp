/*
 * General:
 *	1. Every parameter should be default const&. Write that first and then open as needed.
 *	2. While loops with a manual ++ increment at the end should be converted to for loops.
 *	3. std::distance is O(1) for random-access iterators, O(n) for forward/bidirectional
 *	4. To create a custom hash, make struct, in it define std::size_t operator() (x) const
 *	5. Comparators must use <, >. Min-Heap/Descending created with std::greater or '>'
 *	5a. Max-Heap/Ascending created with std::less or '<' and is the default
 *	6. Branchless wins when >6% misprediction rate, check godbolt, measure, don't use gut feeling
 *	7. Always double check math of working set size and compare to caches, don't use gut feeling
 *	8. Scaling does not create tail latency; that is created by rehashing, page faults, GC, locking etc
 *	9. If return X; and X is local variable, then NVRO: built in place or moved worst case, else copied
 *
 * Overflow:
 * 	INT_MAX = 2^31 - 1 ~~~~ 2.147 * 10^9 (2.147 billion)
 * 	LLONG_MAX = 2^63 - 1 ~~ 9.22 * 10^18
 *
 * 	Before writing any code:
 * 		1. Find/Ask about the largest value of every variable AND every subexpression
 * 		2. Compare against overflow bounds
 *
 * 	Ceiling Division:
 * 	inline auto cielDiv(int a, int b) -> int { return (a - 1) / b + 1 };
 * 		+1 at the end to account for the ceiling, -1 so that if no remainder, it goes one less which is cancelled out by the +1.
 *
 * Containers:
 * 	std::vector
 * 		default; contiguous; prefetch-friendly
 * 	std::deque
 * 		hierarchy: array of pointers to arrays, this allows random access and fast push/pop both ends
 * 	std::list
 * 		iterator stability provided; linked list
 * 	std::stack, std::queue, std::priority_queue
 * 		narrow the interface. simulate pq with make_heap, push_heap, pop_heap on std::vector
 * 	std::unordered_map
 * 		hashed buckets with linked lists external chaining
 *
 * Memory:
 *	1. std::move only on lvalues that are done, never on temp / return values.
 *	2. Do not std::move temp values or in return statements, don't touch variables after moving
 *	3. std::unique_ptr is claiming ownership of memory block
 *	4. Use .get() or std::move on std::unique_ptr to observe (raw/no ownership) or transfer ownership
 *	5. Raw pointers are non-owning observors are totally valid in modern cpp
 *	6. Shared pointers are for when there are multiple objects that own a specific block of memory
 */
