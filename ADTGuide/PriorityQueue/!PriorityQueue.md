# PRIORITY QUEUE NOTES

## 1. CONCEPTUAL HIERARCHY
```
Priority Queue (ADT - Abstract Data Type)
    ↓ implements using
Partially Ordered Tree/Heap (Data Structure)
    ↓ commonly implemented as
Binary Heap (Specific Implementation)
    ↓ stored as
Array (Physical Representation)
```

## 2. PRIORITY QUEUE (ADT)
**Definition**: Collection where elements have priorities
**Key Operations**:
- `insert(element, priority)` - Add element with priority
- `extractMax()` / `extractMin()` - Remove highest/lowest priority
- `peek()` - View highest/lowest priority without removing
- `isEmpty()` - Check if queue is empty

**Use Cases**: Task scheduling, Dijkstra's algorithm, Huffman coding

## 3. PARTIALLY ORDERED TREE/HEAP (Structure)
**Properties**:
- **Heap Property**: Parent-child ordering relationship
  - Max Heap: Parent ≥ Children
  - Min Heap: Parent ≤ Children
- **Shape Property**: Complete tree (fills left-to-right)

## 4. BINARY HEAP (Implementation)
**Structure**: Complete binary tree
**Array Representation**: For node at index `i`:
- Parent: `(i-1)/2`
- Left child: `2*i + 1`
- Right child: `2*i + 2`

**Time Complexities**:
- Insert: O(log n) - bubble up
- Extract: O(log n) - bubble down
- Peek: O(1) - just access root
- Build heap: O(n)

**Space Complexity**: O(n)

## 5. HEAP OPERATIONS
**Insert (Bubble Up)**:
1. Add element at end of array
2. Compare with parent
3. Swap if violates heap property
4. Repeat until heap property satisfied

**Extract (Bubble Down)**:
1. Remove root element
2. Move last element to root
3. Compare with children
4. Swap with larger/smaller child
5. Repeat until heap property satisfied

## 6. ALTERNATIVE IMPLEMENTATIONS
- Fibonacci Heaps: Better for decrease-key operations
- Binomial Heaps: Good for merging
- Leftist Heaps: Efficient merging
- Skew Heaps: Self-adjusting

## 7. COMPARISON WITH OTHER ADTs
| ADT | Structure | Implementation | Access Pattern |
|-----|-----------|----------------|----------------|
| Stack | Linear | Array/Linked | LIFO |
| Queue | Linear | Array/Linked | FIFO |
| Priority Queue | Tree | Heap | Priority-based |
| Set | Various | Bit Vector/Hash | Membership |

## 8. PRACTICAL NOTES
- Binary heaps are most common for priority queues
- Array implementation is cache-friendly
- Heap sort uses max heap for ascending order
- Priority queues ≠ sorted arrays (different use case)

## 9. HEAP SIMULATION PRACTICE

```
Array: [
    22, 45, 50, 14, 
    8, 10, 35,
]

Binary Heap (1-indexed) - Max Heap:
ndx val
 1 | 
 2 | 
 3 | 
 4 | 
 5 | 
 6 | 
 7 | 

Answer With Visualization:
       50
     /    \
   45      40
  /  \    /  \
 35  30  25  20

Practice Operations:
- Insert 60: Where does it go? What swaps happen?
- Extract max: What becomes new root? Bubble down path?
- Find parent of node 12: index ___
- Find children of node 3: indices ___, ___
```