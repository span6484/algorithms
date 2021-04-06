## 03 

简单

## 04 

https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/

巧妙的旋转看法，像二插搜索树一样

O(M+N)

O(1)

## 05 

o(n)

o(n)

## 09 01 

删除的时候把捣腾到2，然后再倒腾回1

删除O(N) O(N)

## 10_1 O1

坑在这个表示范围很大，但每次都求模不影响

o(n)

o(n) --> 双指针可以降到o(1)

## 10_2 

和上题一模一样

## 11 

不懂这个题出来干嘛

## 12 01 

在棋盘搜索路径，和上次给jdl讲的那道题一样，逆向思维

不能说去整个棋盘搜索，而是拿着整个string去比对

我们先是搜索第一个字母，如果再那么我们BFS每次只用看四周有没有，每次都是O(1)的抉择，有目的性的去走

所以O(M*N)

O(M*N)最坏

## 13 01

典型BFS

O(M*N)

O(M*N)最坏

## 06 

装进去再reverse O(n) O(N)

## 07 

详见LC 105

## 14-1

O(N * N)

O(N)

## 14-2 

痕迹二没得意思，找数学规律，按3分最大

## 25

O(n)

o(1)

## 16 

## 26 

O(MN) 最坏 

O(M+N) 最坏

## 27 01 层次遍历

层次遍历去交换子节点

O(N)

O(2^H)

## 27 02 递归

其实就是每个节点left->left = 右递归 ，反之，但此时left已改变，所以我们要先存一下

O(N)

O(H)

## 28 01 递归

o(n)

0(h)

## 15 

学一下c++二进制存储和转换

## 16 

掌握下幂的规律

O(log2 - N)

O(1)


## 17 略

## 18 

哑结点好用

o(n)

o(1)

## 21 

双指针

o(n)

o(1)

## 22 

跑两次有点蠢，可以双指针，先让快指针想走k-1，然后再同时走，然后同时到达就行

o(n)

o(1)

## 29 

看代码仔细体会

awk '{print NR, "\t", $0}' test.cc

## 31

o(n)

o(n)

## 32 

就是个层次遍历 

o(n)

o(2^h)

## 24

应该很熟悉，三个指针不断地移动 

o(n)

o(1)

## 35 

这道题很简单的一个做法是

首先肯定按顺序生成这些节点连起来，再生成的时候，我们就map记录节点的映射

方便后面random直接找到

o(n)

o(n)

## 32-iii

之字形

用deque前后开工

举个例子

        1

    2       3

4    5   6    7

入队顺序  push_front和back刚好是反的

1    从后读，放前

3，2  从前读，放后

2，7，6

7，6，5，4  从后读，放前

o(n)

o(2^h)


## 33 

后序遍历是 左 | 右 | 根

最后一个是根节点，然后我们用一个p来找到左的最后一个，然后找到右的最后一个，然后分治遍历

o(n*n)

o(h)

## 36

利用中序遍历连就是了

o(N)

o(h)

## 39

用个unordered_map去存

o(n)

o(n)

## 42 DP

每一个格子都是存当前最大的可能

而且自己的状态都是当前加上前一个最大的状态，所以我们这里可以原地操作

O(N)

O(1)

## 45 

核心是自定义排序

x+y < y+x 说明这种语境下x比y小

O(NLOGN)

O(N)

## 46

简单DP

首先都是前一个的base，然后看前两位数是不是满足条件，然后加上i-2的base

o(n)

o(n)


## 47 dp

简单DP，这里padding一下十分巧妙，也是常用方法

这样都甚至不需要去判断和初始化

0 0 0 0
0 1 2 5
0 3 2 1
