*This project has been created as part of the 42 curriculum by cbahry and adadra.*

## Desciption
Push Swap is a project that's aimed to introduce student to sorting algorithms, the main idea is to sort an amount of unique numbers using 2 stacks A and B, and a limited set of operations. At the end stack A should be sorted and B is empty.

## Instructions

### Requirements
- GCC
- Make

### Compilation
``` Makefile
 make
```
### Execution
```bash
 shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
```
## Algorithm Selection and Justification

Different sorting strategies are used depending on the size and structure of the input in order to minimize the number of operations in the Push_swap model.

---

### Selection Sort (Small Inputs)

**Used for:** Very small stacks (≤ 5 elements)

A simple selection-based strategy is used to place elements in order using rotations and swaps.
For small inputs, this approach is optimal because it avoids the overhead of more complex algorithms.

- **Complexity:** O(n²)
- **Justification:** Produces the lowest number of operations for tiny stacks

---

### Chunk-Based Sorting (Medium Inputs)

**Used for:** Medium-sized stacks (≈ 6–500 elements)

The stack is divided into value ranges (“chunks”) based on element ranks. Elements are moved chunk by chunk to stack B, then reconstructed into stack A in sorted order. Rotations are optimized based on element positions.

- **Complexity:** ~O(n√n)
- **Justification:** Adaptive to input disorder and performs significantly fewer operations than radix sort on medium inputs

---

### Radix Sort (Large Inputs)

**Used for:** Large stacks (> 500 elements)

Radix sort processes element ranks bit by bit, moving elements between stacks based on their binary representation. The number of operations depends only on the input size.

- **Complexity:** O(n log n)
- **Justification:** Predictable and scalable for very large inputs where chunk-based methods become inefficient

---

### Overall Approach

By combining these strategies, the program ensures:
- Minimal overhead for small inputs
- Adaptive and efficient behavior for medium inputs
- Guaranteed scalability for large inputs

This hybrid approach achieves strong performance across all evaluation ranges.

## Resources

### Technical References
- **GeeksforGeeks**  
  Used for reviewing classic algorithm concepts such as selection sort, radix sort, time complexity analysis, and bitwise operations.
- **YouTube Educational Content**  
  Various algorithm visualization and explanation videos were consulted to better understand stack-based sorting strategies and radix sort behavior.

### Use of AI Assistance
AI tools (ChatGPT) were used as a **learning and reasoning aid**, not as a code generator.  
Specifically, AI was used to:
- Clarify algorithmic concepts (selection sort, chunk-based sorting, radix sort)
- Help reason about time complexity in the Push_swap operation model
- Improve explanations and documentation for evaluation readiness
