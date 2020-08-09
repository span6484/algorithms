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

# Tail call

A simple tail recursive function:

```cpp
unsigned int f( unsigned int a ) {
   if ( a == 0 ) {
      return a;
   }
   return f( a - 1 );   // tail recursion
}
```

A simple tail recursive function:

unsigned int f( unsigned int a ) {
   if ( a == 0 ) {
      return a;
   }
   return f( a - 1 );   // tail recursion
}
Tail recursion is basically when:

there is only a single recursive call that call is the last statement in the function And it's not "better", except in the sense that a good compiler can remove the recursion, transforming it into a loop. This may be faster and will certainly save on stack usage. The GCC compiler can do this optimisation.





