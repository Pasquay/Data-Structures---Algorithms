#include <stdio.h>
#include <stdlib.h>

// Maximum number of processes the scheduler can hold
#define MAX_PROCESSES 10

// Process Structure
// A structure representing a task/process in the operating system.
typedef struct {
    int pid;      // Process ID (Unique Identifier)
    int priority; // Priority level (Higher number = Higher priority)
} Process;

// Priority Queue Structure (Max Heap Implementation)
// The heap array will store the processes.
typedef struct {
    Process heap[MAX_PROCESSES]; // Array to store the heap elements
    int size;                    // Current number of processes in the queue
    int capacity;                // Maximum capacity of the queue
} PriorityQueue;

void initQueue(PriorityQueue *pq);
void swap(Process *a, Process *b);
void heapifyDown(PriorityQueue *pq, int index);
void insertProcess(PriorityQueue *pq, Process newProcess);
Process extractMax(PriorityQueue *pq);
void printQueue(PriorityQueue *pq);
void runEnqueueTest(void);
void runDequeueTest(void);
void runCombinationTest(void);
 
/**
 * @brief Prints the current processes in the queue (in heap order, not sorted).
 * @param pq Pointer to the PriorityQueue.
 */
void printQueue(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Current Ready Queue: [Empty]\n");
        return;
    }

    printf("\n--- Current Ready Queue (Heap Order: Priority, PID) ---\n");
    for (int i = 0; i < pq->size; i++) {
        printf("| P%d (Pri:%d) ", pq->heap[i].pid, pq->heap[i].priority);
    }
    printf("|\n------------------------------------------------------\n");
}

int main() {
    int choice = 3;

    printf("=============== OS SCHEDULER PRIORITY QUEUE MENU ===============");
    printf("\nSelect a Test Scenario to Run:");
    printf("\n1. Enqueue Test (Demonstrates Max Heap build on insertion)");
    printf("\n2. Dequeue Test (Demonstrates Max Heap extraction/scheduling)");
    printf("\n3. Full Combination Test (Dynamic OS Scheduling Scenario)");
    printf("\n==================================================================");
    // printf("\nEnter your choice (1, 2, or 3): ");
    printf("\nEnter your choice (1, 2, or 3): %d\n", choice);

    switch (choice) {
        case 1:
            runEnqueueTest();
            break;
        case 2:
            runDequeueTest();
            break;
        case 3:
            runCombinationTest();
            break;
        default:
            printf("\n\n--- INVALID CHOICE: Please selected 1, 2, or 3. Exiting. ---\n");
            break;
    }

    printf("\nProgram finished execution.\n");

    return 0;
}

// write your functions here
void initQueue(PriorityQueue *pq){
    pq->size = 0;
    pq->capacity = MAX_PROCESSES;
    printf("\n--- Scheduler Queue initialized with capacity 10. ---\n");
}

void swap(Process *a, Process *b){
    Process temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int ndx)    { return (ndx-1)/2; }
int leftChild(int ndx) { return (ndx*2)+1; }
int rightChild(int ndx){ return (ndx*2)+2; }

void heapifyUp(PriorityQueue *pq, int ndx){
    for(; ndx>0 && pq->heap[ndx].priority>pq->heap[parent(ndx)].priority; swap(&pq->heap[ndx], &pq->heap[parent(ndx)]), ndx=parent(ndx)){}
}

void insertProcess(PriorityQueue *pq, Process newProcess){
    if(pq->size<pq->capacity){
        pq->heap[pq->size] = newProcess;
        heapifyUp(pq, pq->size++);
        printf("-> ENQUEUED: Process ID %d (Priority: %d)\n", newProcess.pid, newProcess.priority);
    }
}

void heapifyDown(PriorityQueue *pq, int ndx){
    while(leftChild(ndx)<pq->size && (pq->heap[ndx].priority < pq->heap[leftChild(ndx)].priority || pq->heap[ndx].priority < pq->heap[rightChild(ndx)].priority)){
        if(pq->heap[leftChild(ndx)].priority > pq->heap[rightChild(ndx)].priority){
            swap(&pq->heap[ndx], &pq->heap[leftChild(ndx)]);
            ndx = leftChild(ndx);
        } else {
            swap(&pq->heap[ndx], &pq->heap[rightChild(ndx)]);
            ndx = rightChild(ndx);
        }
    }
}

Process extractMax(PriorityQueue *pq){
    Process retval = (Process){0, 0};
    if(pq->size){
        swap(&retval, &pq->heap[0]);
        swap(&pq->heap[0], &pq->heap[--pq->size]);
        heapifyDown(pq, 0);
    }
    return retval;
}


// =================================================================
//                 TEST SCENARIOS IMPLEMENTATION
// =================================================================

/**
 * @brief Test Scenario 1: Focuses solely on Enqueuing processes.
 * Demonstrates how the Max Heap is built upon insertion.
 */
void runEnqueueTest() {
    PriorityQueue schedulerQueue;
    initQueue(&schedulerQueue);

    printf("\n--- Test 1: ENQUEUE (Process Arrival) ---\n");
    printf("Inserting processes in various priority orders:\n");

    insertProcess(&schedulerQueue, (Process){.pid = 10, .priority = 5});
    insertProcess(&schedulerQueue, (Process){.pid = 20, .priority = 8}); // Higher priority than 10
    insertProcess(&schedulerQueue, (Process){.pid = 30, .priority = 3});
    insertProcess(&schedulerQueue, (Process){.pid = 40, .priority = 9}); // Highest priority
    insertProcess(&schedulerQueue, (Process){.pid = 50, .priority = 7});

    printQueue(&schedulerQueue);
    printf("NOTE: The highest priority process (PID 40, Pri 9) is at the top of the heap (first in the list).\n");
}

/**
 * @brief Test Scenario 2: Focuses solely on Dequeuing processes.
 * Requires pre-loading data to demonstrate extraction behavior.
 */
void runDequeueTest() {
    PriorityQueue schedulerQueue;
    initQueue(&schedulerQueue);

    printf("\n--- Test 2: DEQUEUE (Scheduling Dispatch) ---\n");
    printf("Pre-loading 5 processes for scheduling...\n");

    // Pre-load data
    insertProcess(&schedulerQueue, (Process){.pid = 100, .priority = 4});
    insertProcess(&schedulerQueue, (Process){.pid = 200, .priority = 1});
    insertProcess(&schedulerQueue, (Process){.pid = 300, .priority = 6});
    insertProcess(&schedulerQueue, (Process){.pid = 400, .priority = 3});
    insertProcess(&schedulerQueue, (Process){.pid = 500, .priority = 5});

    printf("\nReady Queue before dispatch:\n");
    printQueue(&schedulerQueue);

    printf("\nDispatching processes in order of priority (Max Heap extraction):\n");
    while (schedulerQueue.size > 0) {
        Process dispatched = extractMax(&schedulerQueue);
        if (dispatched.pid != -1) {
            printf("<- DEQUEUED: SCHEDULING Process ID %d (Priority: %d)\n", dispatched.pid, dispatched.priority);
            printQueue(&schedulerQueue); // Show state after each dispatch
        }
    }
    printf("\nQueue is now empty.\n");
}

/**
 * @brief Test Scenario 3: The original combination of Enqueue and Dequeue,
 * demonstrating a dynamic scheduling environment.
 */
void runCombinationTest() {
    PriorityQueue schedulerQueue;
    initQueue(&schedulerQueue);

    printf("\n--- Test 3: COMBINATION (Dynamic OS Scheduling) ---\n");

    printf("\n--- STEP 1: Process Arrival (Enqueuing Tasks) ---\n");

    // Scenario: High priority interactive task arrives
    insertProcess(&schedulerQueue, (Process){.pid = 101, .priority = 9}); // High priority
    // Scenario: Background job arrives
    insertProcess(&schedulerQueue, (Process){.pid = 205, .priority = 3}); // Low priority
    // Scenario: Medium-priority system task
    insertProcess(&schedulerQueue, (Process){.pid = 312, .priority = 5}); // Medium priority
    // Scenario: Another background job arrives (lower priority than previous one)
    insertProcess(&schedulerQueue, (Process){.pid = 400, .priority = 2}); // Lowest priority

    printQueue(&schedulerQueue);

    printf("\n--- STEP 2: Scheduler Dispatch (Dequeuing Highest Priority) ---\n");

    // The scheduler picks the task with the highest priority (PID 101, Pri 9)
    Process dispatched1 = extractMax(&schedulerQueue);
    printf("<- DEQUEUED: SCHEDULING Process ID %d (Priority: %d)\n", dispatched1.pid, dispatched1.priority);

    // Scenario: A new critical process arrives while others are waiting
    printf("\nNew critical process arrives:\n");
    insertProcess(&schedulerQueue, (Process){.pid = 550, .priority = 10}); // NEW Highest priority

    printQueue(&schedulerQueue);

    // The scheduler picks the next task. It should be PID 550 (Pri 10) now.
    Process dispatched2 = extractMax(&schedulerQueue);
    printf("<- DEQUEUED: SCHEDULING Process ID %d (Priority: %d)\n", dispatched2.pid, dispatched2.priority);

    // Continue scheduling the remaining tasks
    printf("\n--- STEP 3: Scheduling Remaining Tasks ---\n");

    while (schedulerQueue.size > 0) {
        Process dispatched = extractMax(&schedulerQueue);
        printf("<- DEQUEUED: SCHEDULING Process ID %d (Priority: %d)\n", dispatched.pid, dispatched.priority);
    }

    printf("\nAll processes have been scheduled and executed in priority order.\n");
}