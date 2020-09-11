## recursion

## Basis

basic case / recurrence relation

## complexity

Time complexity:

the product of the number of recursion invocations (denoted as R) and the time complexity of calculation (denoted as O(s)) that incurs along with each recursion call.

O(T) = R * O(s)

Space complexity:

- recursion related and non-recursion related space.

- Recursion Related Space:

the stack to keep track of recursive function calls

In order to complete a typical function call, the system allocates some space in the stack to hold three important pieces of information:

1. The returning address of the function call. Once the function call is completed, the program must know where to return to, i.e. the line of code after the function call.

2. The parameters that are passed to the function call. 

3. The local variables within the function call.

once the function call is done, this space is freed. 

- Non-Recursion Related Space

## Tail Recursion

Tail recursion is a recursion where the recursive call is the final instruction in the recursion function. And there should be only one recursive call in the function,
its return value is not part of the expression. 

It overwrites the current active record instead of creating a new one on the stack.

```cpp
int helper_non_tail_recursion(int start, vector<int> ls) {
    if (start >= ls.size()) {
        return 0;
    }
    // not a tail recursion because it does some computation after the recursive call returned.
    return ls[start] + helper_non_tail_recursion(start+1, ls);
}

int helper_tail_recursion(int start, vector<int> ls, int acc) {
    if (start >= ls.size()) {
        return acc;
    }
    // this is a tail recursion because the final instruction is the recursive call.
    return helper_tail_recursion(start+1, ls, acc+ls[start]);
}

```

Take another example:

```cpp
long Rescuvie(long n) {
    return (n == 1) ? 1 : n * Rescuvie(n - 1);
}
```

```cpp
long TailRescuvie(long n, long a) {
    return (n == 1) ? a : TailRescuvie(n - 1, a * n);
}
 
long TailRescuvie(long n) { //wrapper 
    return (n == 0) ? 1 : TailRescuvie(n, 1);
 
}
```

```bash
Rescuvie(5)
{5 * Rescuvie(4)}
{5 * {4 * Rescuvie(3)}}
{5 * {4 * {3 * Rescuvie(2)}}}
{5 * {4 * {3 * {2 * Rescuvie(1)}}}}
{5 * {4 * {3 * {2 * 1}}}}
{5 * {4 * {3 * 2}}}
{5 * {4 * 6}}
{5 * 24}
120
```

```bash
TailRescuvie(5)
TailRescuvie(5, 1)
TailRescuvie(4, 5)
TailRescuvie(3, 20)
TailRescuvie(2, 60)
TailRescuvie(1, 120)
120
```

The essence of tail recursion is that there is one more parameter than linear recursion, which is the result of the last call to the function;
Therefore, the key point is that tail recursion collects the results every time it is called, which avoids the disadvantage of linear recursion that does not collect results and can only expand and consume memory sequentially.


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

## 104. Maximum Depth of Binary Tree 01 tail recursion

Here we add a depth parameter to store the record.

TC: O(n)

SC: O(1)

## 50. Pow(x, n) 01 tail recursion

Time complexity : O(logN)

Space complexity : O(1)

O(N) exceed the time limit 

16 is 2^4 and (2*2) ^ 2 and (4*4) ^ 1

So we can conjuer up the divide-and-conquer algorithms.

Be careful -1 * INT_MIN = INT_MAX + 1

So we use long to cast the type

Q:  Why do we usually use dichotomy rather than thirds?

## 21. Merge Two Sorted Lists 01 recursion

TC : O(N)

SP : O(N)

## 779. K-th Symbol in Grammar 01 recursion 

The whole structure can be viewed a binary tree, when a node is 0, their two children nodes are 0 and 1, similarly, when a node is 1. We can know whether the position of K is a left node or a right node by dividing 2. If K is even, current node is right child, and its parent is the (K/2)th node in previous row;
The value of current node depends on its parent node, without knowing its parent node value, we still cannot determine current node value. That's why we need recursion, we keep going previous row to find the parent node until reach the first row. Then all the parent node value will be determined after the recursion function returns.

TC: O(N)

SP: O(N)


# Similar

## 687. Longest Univalue Path 01 recursion

TC : O(N)

SC : O(H)

## 543. Diameter of Binary Tree 01 recursion

TC : O(N)

SC : O(H)

## 124. Binary Tree Maximum Path Sum 01 recursion

TC : O(N)

SC : O(H)

## 124. Binary Tree Maximum Path Sum 02 recursion

TC : O(N)

SC : O(H)

## 938. Range Sum of BST 01 recursion

TC : O(n)

SC : O(H)

## 938. Range Sum of BST 02 recursion

TC : O(n)

SC : O(H)

## 783. Minimum Distance Between BST Nodes 01 recursion

Actually, the essence of this question is sorting.

And we know that BST'S sorting equals to the inorder tranverse.

TC: O(N)

SP: O(H)

## 1137. N-th Tribonacci Number 01 recursion dp

The same as fibnacci

TC: O(n)

SC : O(N)

## 894. All Possible Full Binary Trees 01 recursion

1. Be careful, the number of node must be odd.

2. Subtrees are solutions from smaller problems.

```python
trees(n):
    for i = 1 to n, step 2:
        root.left := trees(i)
        root.right := trees(n-i-1)
```

The time complexity and space complexity are always equal to the size of the output????


https://www.youtube.com/watch?v=noVVstnQvyY

https://zxi.mytechroad.com/blog/tree/leetcode-894-all-possible-full-binary-trees/

https://www.cnblogs.com/grandyang/p/10952459.html

https://leetcode-cn.com/circle/article/lWYCzv/

## 894. All Possible Full Binary Trees 02 dp

To store the smaller num size subtree.

TC : O(2 ^ N) ?? 

SC : O(2 ^ N) ??