# CPU Task Scheduling - Binary Heap P.Q.
# TEST CASES
by Edwin Bartlett

[1. Instructions](!instructions.md)

[2. Test Cases](!test_cases.md)

---

[#1] Enqueue Test (Demonstrates Max Heap build on insertion)
----------------------------------------------------
```
 OS SCHEDULER PRIORITY QUEUE MENU 
Select a Test Scenario to Run:

Enqueue Test (Demonstrates Max Heap build on insertion)
Dequeue Test (Demonstrates Max Heap extraction/scheduling)
Full Combination Test (Dynamic OS Scheduling Scenario)
Enter your choice (1, 2, or 3): 1
--- Scheduler Queue initialized with capacity 10. ---

--- Test 1: ENQUEUE (Process Arrival) ---
Inserting processes in various priority orders:
-> ENQUEUED: Process ID 10 (Priority: 5)
-> ENQUEUED: Process ID 20 (Priority: 8)
-> ENQUEUED: Process ID 30 (Priority: 3)
-> ENQUEUED: Process ID 40 (Priority: 9)
-> ENQUEUED: Process ID 50 (Priority: 7)

--- Current Ready Queue (Heap Order: Priority, PID) ---
| P40 (Pri:9) | P20 (Pri:8) | P30 (Pri:3) | P10 (Pri:5) | P50 (Pri:7) |
NOTE: The highest priority process (PID 40, Pri 9) is at the top of the heap (first in the list).

Program finished execution.```
```

----------------------------------------------------
[#2] Dequeue Test (Demonstrates Max Heap extraction/scheduling)
----------------------------------------------------

``` OS SCHEDULER PRIORITY QUEUE MENU 
Select a Test Scenario to Run:

Enqueue Test (Demonstrates Max Heap build on insertion)
Dequeue Test (Demonstrates Max Heap extraction/scheduling)
Full Combination Test (Dynamic OS Scheduling Scenario)
Enter your choice (1, 2, or 3): 2
--- Scheduler Queue initialized with capacity 10. ---

--- Test 2: DEQUEUE (Scheduling Dispatch) ---
Pre-loading 5 processes for scheduling...
-> ENQUEUED: Process ID 100 (Priority: 4)
-> ENQUEUED: Process ID 200 (Priority: 1)
-> ENQUEUED: Process ID 300 (Priority: 6)
-> ENQUEUED: Process ID 400 (Priority: 3)
-> ENQUEUED: Process ID 500 (Priority: 5)

Ready Queue before dispatch:

--- Current Ready Queue (Heap Order: Priority, PID) ---
| P300 (Pri:6) | P500 (Pri:5) | P100 (Pri:4) | P200 (Pri:1) | P400 (Pri:3) |
Dispatching processes in order of priority (Max Heap extraction):
<- DEQUEUED: SCHEDULING Process ID 300 (Priority: 6)

--- Current Ready Queue (Heap Order: Priority, PID) ---
| P500 (Pri:5) | P400 (Pri:3) | P100 (Pri:4) | P200 (Pri:1) |
<- DEQUEUED: SCHEDULING Process ID 500 (Priority: 5)

--- Current Ready Queue (Heap Order: Priority, PID) ---
| P100 (Pri:4) | P400 (Pri:3) | P200 (Pri:1) |
<- DEQUEUED: SCHEDULING Process ID 100 (Priority: 4)

--- Current Ready Queue (Heap Order: Priority, PID) ---
| P400 (Pri:3) | P200 (Pri:1) |
<- DEQUEUED: SCHEDULING Process ID 400 (Priority: 3)

--- Current Ready Queue (Heap Order: Priority, PID) ---
| P200 (Pri:1) |
<- DEQUEUED: SCHEDULING Process ID 200 (Priority: 1)
Current Ready Queue: [Empty]

Queue is now empty.

Program finished execution.```
```

---

[#3] Full Combination Test (Dynamic OS Scheduling Scenario)
----------------------------------------------------

```
OS SCHEDULER PRIORITY QUEUE MENU 

Select a Test Scenario to Run:

Enqueue Test (Demonstrates Max Heap build on insertion)
Dequeue Test (Demonstrates Max Heap extraction/scheduling)
Full Combination Test (Dynamic OS Scheduling Scenario)
Enter your choice (1, 2, or 3): 3
--- Scheduler Queue initialized with capacity 10. ---

--- Test 3: COMBINATION (Dynamic OS Scheduling) ---

--- STEP 1: Process Arrival (Enqueuing Tasks) ---
-> ENQUEUED: Process ID 101 (Priority: 9)
-> ENQUEUED: Process ID 205 (Priority: 3)
-> ENQUEUED: Process ID 312 (Priority: 5)
-> ENQUEUED: Process ID 400 (Priority: 2)

--- Current Ready Queue (Heap Order: Priority, PID) ---
| P101 (Pri:9) | P205 (Pri:3) | P312 (Pri:5) | P400 (Pri:2) |
--- STEP 2: Scheduler Dispatch (Dequeuing Highest Priority) ---
<- DEQUEUED: SCHEDULING Process ID 101 (Priority: 9)

New critical process arrives:
-> ENQUEUED: Process ID 550 (Priority: 10)

--- Current Ready Queue (Heap Order: Priority, PID) ---
| P550 (Pri:10) | P312 (Pri:5) | P400 (Pri:2) | P205 (Pri:3) |
<- DEQUEUED: SCHEDULING Process ID 550 (Priority: 10)

--- STEP 3: Scheduling Remaining Tasks ---
<- DEQUEUED: SCHEDULING Process ID 312 (Priority: 5)
<- DEQUEUED: SCHEDULING Process ID 205 (Priority: 3)
<- DEQUEUED: SCHEDULING Process ID 400 (Priority: 2)

All processes have been scheduled and executed in priority order.

Program finished execution.```

---