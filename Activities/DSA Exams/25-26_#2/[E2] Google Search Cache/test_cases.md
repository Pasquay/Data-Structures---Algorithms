[#1] New Key Insertion (famous cse concepts)
----------------------------------------------------
Note: Test Cases 2 and 3 require Test 1 to be run first.

Select a test case to run:
1. Run Test 1: New Key Insertion (famous cse concepts)
2. Run Test 2: Existing Key Lookup (Expected HIT)
3. Run Test 3: Redundant Insertion (Expected SKIP)
4. Run Test 4: Second New Key Insertion (latest google earnings report)
5. Run Test 5: Non-existent Key (DB No Results)
0. Exit and Free Memory
Enter choice: 1

--- Test 1: New Key Insertion (famous cse concepts) ---
```
  [Lookup Status] Key 'famous cse concepts' MISS. Attempting to fetch and insert (DB QUERY in progress)...
  [Insert Status] Insertion successful (DB fetched and cached).
Search results for 'famous cse concepts' (3 results):
  1. Big O Notation: Analyzing Algorithm Efficiency
  2. Turing Machine: The Theoretical Model of Computation
  3. B+ Tree Indexing: Optimizing Database Lookups
```

--- Cache memory successfully freed. ---

[#2] Existing Key Lookup (famous cse concepts)
----------------------------------------------------
Note: Test Cases 2 and 3 require Test 1 to be run first.

Select a test case to run:
1. Run Test 1: New Key Insertion (famous cse concepts)
2. Run Test 2: Existing Key Lookup (Expected HIT)
3. Run Test 3: Redundant Insertion (Expected SKIP)
4. Run Test 4: Second New Key Insertion (latest google earnings report)
5. Run Test 5: Non-existent Key (DB No Results)
0. Exit and Free Memory
Enter choice: 1

--- Test 1: New Key Insertion (famous cse concepts) ---
```
  [Lookup Status] Key 'famous cse concepts' MISS. Attempting to fetch and insert (DB QUERY in progress)...
  [Insert Status] Insertion successful (DB fetched and cached).
Search results for 'famous cse concepts' (3 results):
  1. Big O Notation: Analyzing Algorithm Efficiency
  2. Turing Machine: The Theoretical Model of Computation
  3. B+ Tree Indexing: Optimizing Database Lookups
```

--- Cache memory successfully freed. ---

[#3] Redundant Insertion (famous cse concepts)
----------------------------------------------------
Note: Test Cases 2 and 3 require Test 1 to be run first.

Select a test case to run:
1. Run Test 1: New Key Insertion (famous cse concepts)
2. Run Test 2: Existing Key Lookup (Expected HIT)
3. Run Test 3: Redundant Insertion (Expected SKIP)
4. Run Test 4: Second New Key Insertion (latest google earnings report)
5. Run Test 5: Non-existent Key (DB No Results)
0. Exit and Free Memory
Enter choice: 1

--- Test 1: New Key Insertion (famous cse concepts) ---
```
  [Lookup Status] Key 'famous cse concepts' MISS. Attempting to fetch and insert (DB QUERY in progress)...
  [Insert Status] Insertion successful (DB fetched and cached).
Search results for 'famous cse concepts' (3 results):
  1. Big O Notation: Analyzing Algorithm Efficiency
  2. Turing Machine: The Theoretical Model of Computation
  3. B+ Tree Indexing: Optimizing Database Lookups
```

--- Test 3: Redundant Insertion Test (famous cse concepts) ---
```
  [Insert Status] Insertion was logically skipped because key 'famous cse concepts' already exists.
  Note: No DB fetch occurred. Cache results are unchanged.
Search results for 'famous cse concepts' (3 results):
  1. Big O Notation: Analyzing Algorithm Efficiency
  2. Turing Machine: The Theoretical Model of Computation
  3. B+ Tree Indexing: Optimizing Database Lookups
```

--- Cache memory successfully freed. ---

[#4] Second New Key Insertion (latest google earnings report)
----------------------------------------------------
Note: Test Cases 2 and 3 require Test 1 to be run first.

Select a test case to run:
1. Run Test 1: New Key Insertion (famous cse concepts)
2. Run Test 2: Existing Key Lookup (Expected HIT)
3. Run Test 3: Redundant Insertion (Expected SKIP)
4. Run Test 4: Second New Key Insertion (latest google earnings report)
5. Run Test 5: Non-existent Key (DB No Results)
0. Exit and Free Memory
Enter choice: 1

--- Test 1: New Key Insertion (famous cse concepts) ---
```
  [Lookup Status] Key 'famous cse concepts' MISS. Attempting to fetch and insert (DB QUERY in progress)...
  [Insert Status] Insertion successful (DB fetched and cached).
Search results for 'famous cse concepts' (3 results):
  1. Big O Notation: Analyzing Algorithm Efficiency
  2. Turing Machine: The Theoretical Model of Computation
  3. B+ Tree Indexing: Optimizing Database Lookups
```

--- Test 4: Another New Key Insertion (latest google earnings report) ---
```
  [Lookup Status] Key 'latest google earnings report' MISS. Attempting to fetch and insert (DB QUERY in progress)...
  [Insert Status] Insertion successful (DB fetched and cached).
Search results for 'latest google earnings report' (3 results):
  1. Q4 2024 Alphabet Earnings Release Summary
  2. Transcript of Latest Investor Earnings Call
  3. Analyst Projections for Next Quarter
```

--- Test 2: Existing Key Lookup (famous cse concepts) ---
```
  [Lookup Status] Key 'famous cse concepts' HIT. Returning cached results.
Search results for 'famous cse concepts' (3 results):
  1. Big O Notation: Analyzing Algorithm Efficiency
  2. Turing Machine: The Theoretical Model of Computation
  3. B+ Tree Indexing: Optimizing Database Lookups
```

--- Cache memory successfully freed. ---

[#5] Non-existent Key (unrelated cat facts)
----------------------------------------------------
Note: Test Cases 2 and 3 require Test 1 to be run first.

Select a test case to run:
1. Run Test 1: New Key Insertion (famous cse concepts)
2. Run Test 2: Existing Key Lookup (Expected HIT)
3. Run Test 3: Redundant Insertion (Expected SKIP)
4. Run Test 4: Second New Key Insertion (latest google earnings report)
5. Run Test 5: Non-existent Key (DB No Results)
0. Exit and Free Memory
Enter choice: 5

--- Test 5: Non-existent Key (unrelated cat facts) ---
```
  [Lookup Status] Key 'unrelated cat facts' MISS. Attempting to fetch and insert (DB QUERY in progress)...
  [Insert Status] Insertion aborted because DB returned no valid results.
Search results for 'unrelated cat facts': No results.
```

--- Cache memory successfully freed. ---
