## 二分查找

模板

```cpp
// [l, r)
l  = lowerest 
r = highest + 1
while l < r:
    m = l+(r-l)/2
    // if f(m) : return m  // optional
    if cond(m)
        r = m
    else 
        l = m + 1
return l;

Time O(log(r-l) * (f(m) + cond( m)))

```

lower_bound()

upper_bound()

demo : demo01.cc

## 4. Median of Two Sorted Arrays 01 

todo review

## 1760. Minimum Limit of Balls in a Bag 01 

Constraints:

1 <= nums.length <= 10^5   -- 说明复杂度为要小于 N^2

1 <= maxOperations, nums[i] <= 10^9  -- o(1) or O(logN)

review : 

1. priority queue

2. max_element

O(logm * n)

O(1)

## 69. Sqrt(x) 01

log(x)

o(1)

## 278. First Bad Version 01

log(m)

o(1)

## 875. Koko Eating Bananas 01 

模板，注意这里是within,所以<=

log(m) * n

o(1)

## 378. Kth Smallest Element in a Sorted Matrix 01 

这里利用二分法找第k大的数，看似巧妙，其实应该能想到

找一个范围某个数，有序，都该想到二分，好好理解此题

logm * nlogn

o1

## 1011. Capacity To Ship Packages Within D Days 01 二分

可以明确最低运载能力必须要不小于数组中的最大值（必须要满足一天至少运一个，运载能力至少要比每个包裹的重量都要大才行，不然就会出现有包裹一直运不走），不大于数组的总和（一天全部运走），即区间[max(weights), sum(weights)];

O(log(sum_vec) * n)

O(1)

## 33. Search in Rotated Sorted Array

利用二分查找

先检查左右两侧哪边有序，在有序的一方再比较大小

o(logn)

## 1482. Minimum Number of Days to Make m Bouquets

O(mlogn)

o(1)

## 34. Find First and Last Position of Element in Sorted Array 01

很明显的二分法

因为找到了，可能左边有，可能右边有，索性分成两个来搞，也可以加个bool变量区分

o(logn)

o(1)

## 34. Find First and Last Position of Element in Sorted Array 02

加个bool变量复用

## 34. Find First and Last Position of Element in Sorted Array 03

利用lower_bound upper_bound来找

o(logn)

o(1)