## 堆

https://zhuanlan.zhihu.com/p/111734399

堆排序，原地，nlogn, 不稳定

插入和删除主要靠堆化，复杂度都为log(n)

1. 建堆 ON

2. 排序 nlogn

## 23. Merge k Sorted Lists

学会利用priority_queue

构建最小堆，每次取堆顶

o(nlogk)

o(k)

## 215. Kth Largest Element in an Array

静态最小堆

o(nlogk)

o(k)

## 239. Sliding Window Maximum

用一个index来判断，当上面一层index小，说明出去了，就pop出去

最坏

o(nlogn)

o(n)

## 264. Ugly Number II

如果n是一个丑数，那么n*2, n*3, n*5也是

我们用个最小堆

然后用个set来去重

o(nlogn)

o(n)

## 295. Find Median from Data Stream

2,3,4

2 

2 3 

2,3 4

用一个最大堆lo 存放小的一半，一个最小堆，存在大的一半

添加的时候，先添加到最大堆，然后这里排了序，再把top给最小堆排序

然后还有个平衡操作，因为这样的话那么我们每次相当于丢进hi了

所以当左半边小了要丢回来

这样的话，左边要么多一个就是median，要么就是两个top的一半

add o(logn)

find O(1)

空间o(n)

## 1244. Design A Leaderboard

addScore/ reset o(logn) 

topk o(N)

o(1)