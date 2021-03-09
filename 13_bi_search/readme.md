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

278. First Bad Version 01

log(m)

o(1)
