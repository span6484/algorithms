## DFS

DFS就是回溯

```cpp

```

## BFS

 BFS 的本质 求最短路径

BFS 相对 DFS 的最主要的区别是：BFS 找到的路径一定是最短的，但代价就是空间复杂度比 DFS 大很多

BFS 还是有代价的，一般来说在找最短路径的时候使用 BFS，其他时候还是 DFS 使用得多一些（主要是递归代码好写）

框架

```cpp
// 计算从起点 start 到终点 target 的最近距离
int BFS(Node* start, Node* target) {
    queue<Node*> q; // 核心数据结构
    unordered_set<Node*> visited; // 避免走回头路

    q.push(start); // 将起点加入队列
    visited.insert(start);
    int step = 0; // 记录扩散的步数

    while(!q.empty()) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散 */
        for (int i = 0; i < sz; i++) {
            auto cur = q.front(); q.pop();
            /* 划重点：这里判断是否到达终点 */
            if (cur is target)
                return step;
            /* 将 cur 的相邻节点加入队列 */
            for (Node* x : cur.adj())
                if (x not in visited) {
                    q.push(x);
                    visited.insert(x);
                }
        }
        /* 划重点：更新步数在这里 */
        step++;
    }
}
```

## 111. Minimum Depth of Binary Tree 01 BFS Queue

一定注意，for(int i = 0; i < xxx.size(); i++) 的时候一定注意xxx变化了没，最好提前求出size

这里BFS层次遍历

O(N)

O(N)

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

## 752. Open the Lock 02 BFS

更加框架化，感觉用unordered_map写起要方便点，这里比较巧的是把deadend直接当visited了，反正不会从这过，这是一个小trick

## 279. Perfect Squares 01 BFS

这道题也是很明显的一道最短路径问题，利用BFS模板即可，和752差不多，每次只是去减去一个平方数操作。

这道题把想成树那个图就明白为什么是可以用BFS，这里说了最少也是提醒最短路径

![279](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjc5LzI3OV9ncmVlZHlfdHJlZS5wbmc?x-oss-process=image/format,png)

## 279. Perfect Squares 02 DP


## 155. Min Stack 01 vector

我们这里简单利用vector来模拟栈

## 155. Min Stack 02 two stack


## 20. Valid Parentheses 01 

三种遇到配的情况就pop，不然的话就push

时间复杂度为O(N), 空间复杂度为O(N)

## 20. Valid Parentheses 02

我们这里遇到左括号，我们就push对应的右括号，如果我们在这个过程中，遇到右括号，但是栈为空，或者栈顶不等于这个右括号，及不对应，则直接false，其他情况就是对应pop。最后我们判断是否完全对应，如果栈为空则为true

时间复杂度为O(N),空间复杂度为O(N)

## 739. Daily Temperatures

我们这里利用一个单调栈，我们存储下标，当当前元素大于栈顶元素的时候(当访问栈顶一定要保证栈不为空)，则计算下标之差存入res的那个位置中，然后循环比较，然后pop，否则的话就存入当前的index。

因为只遍历一次，然后只需维护一个栈，时间复杂度为O(N),空间复杂度为O(N)

## 150. Evaluate Reverse Polish Notation 

知识点:前缀表达式(波兰式) 后缀表达式(逆波兰式)

中缀表达式 : a + b

前缀表达式 : + a b 

后缀表达式 : a b +

- 中转前

1. 每一个表达式用括号括起来

2. 两个表达式中间的运算符提至括号外

for example 

(a+b)*c+d-(e+g)*h

((a+b)*c)+d-((e+g)*h)

(((a+b)*c)+d)-((e+g)*h)

( (((a+b)*c)+d)-((e+g)*h) )

- (((a+b)*c)+d) ((e+g)*h) 

- + ((a+b)*c) d ((e+g)*h)

- + * (a+b) c d ((e+g)*h)

- + * + a b c d ((e+g)*h)

- + * + a b c d * (e+g) h

- + * + a b c d * + e g h

后缀就是往后丢，此处略 ab+c*d+eg+h*-

- 后缀转中缀方法

其实这里用个栈就可以了，遇到数字我们就push进来，遇到op我们就弹出两个值运算再压入。

注意c++ 的 switch必须要一个int，所以比较麻烦，还是都写if else把

这里只需要循环一次，时间复杂度为O(N), 空间复杂度为O(N)

## 133. Clone Graph 01 DFS 递归 数组模拟映射

我们利用题目条件1 <= Node.val <= 100，设置一个100维数组作为int - Node*的映射，克隆图就是一个遍历，如果在数组中存在，那么就是经历过的，否则就new一个点，记录入数组中，他的终止条件是为空则返回空，数组中已有则返回数组中的，neibors递归去push_back其点。

因为只用遍历图一次，所以我们时间复杂度为O(N),空间复杂度为O(N)

## 133. Clone Graph 02 DFS 

原理同上，不过用了unordered_map,更加robust

## 133. Clone Graph 03 BFS 

这里就是套模板装进queue里，这里有一个映射,就是原点到新复制点的映射。如果有value则经历过，跳过，没有则new新的点。

这里因为只需要遍历图一次，所以我们时间复杂度为O(N),空间复杂度为O(N)

## 494. Target Sum 01 DFS 暴搜

这道题tips给的数量级可以暴搜解决，我们利用dfs递归寻找二叉树一样寻找每一个路径，然后最后那个点计算满足条件则return 1；

## 818. Race Car 01 BFS 

若小车一直加速的话

0 -> 1 -> 3 -> 7 -> 15 -> 31

当小车从0开始连加n个速的话，其将会到达位置 2^n - 1

可能提前调头，可能冲过后再掉头

我们怎么知道啥时候要掉头？答案是不知道，我们得遍历每种情况

为了避免计算一些无用的情况，比如小车反向过了起点，或者是超过 target 好远都不回头，我们需要限定一些边界

比如小车不能去小于0的位置，以及小车在超过了 target 时，就必须回头了，

小车当前的位置不能超过 target x 2 -- 因为过了之后返回又是和现在一样的问题，怎么走target这么长

求极值的题目，就是 BFS，带剪枝的 DFS 解法，贪婪算法，或者动态规划 Dynamic Programming 这几种解法（带记忆数组的 DFS 解法也可以归到 DP 一类中去）

一般 DP 只能用来求极值，而想求极值对应的具体情况（比如这道题如果让求最少个数的指令是什么），有时候可能还得用带剪枝的 DFS 解法

状态 {pos, speed}

