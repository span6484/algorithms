## recursion

## Basis

basic case / recurrence relation

## complexity

the product of the number of recursion invocations (denoted as R) and the time complexity of calculation (denoted as O(s)) that incurs along with each recursion call.

O(T) = R * O(s)

## 206. Reverse Linked List 01 recursive

Recursive method enters the bottom(here is the end of the list) and then backtracks.

Base case -> recursion -> operation.

TC: O(n)

SC: O(n)

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

## 700. Search in a Binary Search Tree 01 recursion

First this is a BST, so it has an order.

worst:

TC: O(n)

SC: O(n)

# Tail call

