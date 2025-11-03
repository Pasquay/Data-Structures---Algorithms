# CPU Task Scheduling - Binary Heap P.Q.
by Edwin Bartlett

[1. Instructions](!instructions.md)

[2. Test Cases](!test_cases.md)

---

## Introduction

A priority queue is a practical data structure in many real-life situations where items need to be processed or retrieved based on their priority rather than their arrival order (like in a standard queue) or the order they were added (like in a stack). One scenario where a priority queue is highly practical is task/process scheduling in operating systems.

In a **multitasking operating system**, numerous processes or tasks are often ready to run. The OS must decide which one gets the CPU next.

- **Scenario:** The OS scheduler needs to manage active processes.
- **Priority:** Processes are assigned a priority (e.g., high for interactive tasks, low for background jobs).
- **Priority Queue Use:** The priority queue stores all ready processes. The process with the **highest priority** is always dequeued first. This ensures critical or time-sensitive tasks get preference.

---

## Program Specifications

This program defines a `PriorityQueue` using a Max Heap array, where `insertProcess` handles the enqueue operation and `extractMax` simulates the OS scheduler dispatching the task with the highest priority. The output clearly shows how the process with priority 10 gets scheduled ahead of processes with priority 5 and 3, demonstrating the core priority queue logic.

---

## Function Specifications

### `void initQueue(PriorityQueue *pq)`
- Initializes the priority queue structure.
- **Param pq** – Pointer to the PriorityQueue structure.

### `void heapifyDown(PriorityQueue *pq, int index)`
- Restores the Max Heap property by sifting a node down.
- Called after removing the root (highest priority element).
- **param pq** – Pointer to the PriorityQueue.
- **param index** – Index of the node to start sifting down from.

### `void insertProcess(PriorityQueue *pq, Process newProcess)`
- Adds a new process to the queue and maintains the Max Heap property.
- **param pq** – Pointer to the PriorityQueue.
- **param newProcess** – The Process structure to insert.

### `Process extractMax(PriorityQueue *pq)`
- Extracts the process with the highest priority (the root of the Max Heap).
- This simulates the OS scheduler picking the next task.
- **param pq** – Pointer to the PriorityQueue.
- **returns** – The highest priority Process. Returns a dummy process if the queue is empty.

---

## Function Specifications

### `void initQueue(PriorityQueue *pq)`
- Initializes the priority queue structure.
- Param pq - Pointer to the PriorityQueue structure.

### `void heapifyDown(PriorityQueue *pq, int index)`
- Restores the Max Heap property by sifting a node down.
- Called after removing the root (highest priority element).
- param pq - Pointer to the PriorityQueue.
- param index - Index of the node to start sifting down from.

### `void insertProcess(PriorityQueue *pq, Process newProcess)`
- Adds a new process to the queue and maintains the Max Heap property.
- param pq - Pointer to the PriorityQueue.
- param newProcess - The Process structure to insert.

### `Process extractMax(PriorityQueue *pq)`
- Extracts the process with the highest priority (the root of the Max Heap).
- This simulates the OS scheduler picking the next task.
- param pq - Pointer to the PriorityQueue.
- returns - The highest priority Process. Returns a dummy process if the queue is empty.

---

## Blue's Clues

### `initQueue`
- Set the queue's size to 0 and capacity to `MAX_PROCESSES`.

### `heapifyDown`
- Check the left and right child for which is larger. If the largest is not the current node, swap and continue heapifying down.

### `insertProcess`
1. Insert the new process at the end of the heap
2. Restore Max Heap property by sifting up

### `extractMax`
1. Replace the root with the last element
2. Restore the Max Heap property by sifting down the new root

---


















