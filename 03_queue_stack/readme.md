## 622. Design Circular Queue 01

此题注意几点，为什么我们不用head 和 tail 而非要用 tail和size去推算head呢，这是因为会出现enqueue之后我们只动tail而无head的情况，然后我们去front就会出错，这样需要更多判断。如果只用tail的话我们则不需要太多去考虑维护的。

(tail_ - size_ + k_ + 1) % k_ 加个k_就不存在负数的情况了，很巧妙


## 200. Number of Islands 01 DFS

我们遍历循环，当遇到一个陆地的时候，我们DFS将相连的所有设置成2，然后这样就避免了重复。

这样我们和循环遍历一样，时间复杂度为O(MN), M为行数，N为列数。

空间复杂度最坏的情况为全为陆地，我们需要dfs递归MN次，我们需要的空间复杂度最坏为O(MN)

## 200. Number of Islands 02 BFS

我们一个queue存入一个坐标pair，当我们遇到一个1的时候，则岛屿++，我们广度优先看点是否为相连的1，如果是的话则置0(因为我们需要避免重复)，然后入栈。

时间复杂度为O(MN),空间复杂度，最坏的情况为全为陆地，O(min{M,N})

## 200. Number of Islands 03 UNION FIND

见06_disjointed_set

## 752. Open the Lock 01 BFS

这就是一个BFS的最短路径问题，我们这里设置一个hashmap,先构建出deadends，其实这个映射就是添加一个flag，不可走和经过后的点，那就肯定不是target，我们不必再走回头路，所以每次先判断是否是，如果不是设置为1表示我们走到这了，每次就是8种方式的转锁变换，我们添加入栈作为外围继续前进，每一维就是一个step.

## 279. Perfect Squares 01 BFS

这道题也是很明显的一道最短路径问题，利用BFS模板即可，和752差不多，每次只是去减去一个平方数操作。

## 279. Perfect Squares 02 DP

## 155. Min Stack 01 vector

我们这里简单利用vector来模拟栈

## 155. Min Stack 02 two stack


