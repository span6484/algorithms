## recursion

## Basis

basic case / recurrence relation

## 344. Reverse String 01 recursion

To recurse the index which we want to loop.

Time complexity: O(n)

Space complexity: O(n)

## 24. Swap Nodes in Pairs 01 recursion

Every time we do the same repeated operation: swap two nodes and move on, so we conjure up the recursion method, every recursion operation returns that new first head to follow the last one.

The main steps are:

- basic case : We should be careful of NULL when we use linklist

- Traditional change operation

- head->next = helper(head->next->next);  recursion to follow the last one

Time complexity: O(n)

Space complexity: O(n)

