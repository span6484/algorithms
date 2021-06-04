![sort](./assets/01.png)

## 归并排序

```cpp
template<typename T> 
void merge_sort(vector<T>& arr) {
    mergeHelper(arr, 0, arr.size()-1);
}


template<typename T> 
void mergeHelper(vector<T>& arr, int left, int right) {
    if(left >= right) return;  // 1个的时候
    int mid = left + (right-left)/2;
    mergeHelper(arr, left, mid);
    mergeHelper(arr, mid+1, right);
    merge(arr, left, mid, right);
}

template<typename T> 
void merge(vector<T>& arr, int left, int mid, int right) {
    vector<T> tmp(right-left);
    int i = left, j = mid+1, k = 0;
    while(i < mid && j < right) {
        if(arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    // 判断哪个数组还有剩余
    int start = i, end = mid;
    if(j < right) {
        start = j;
        end = right;
    }
    while(start < right) {
        tmp[k++] = arr[start++];
    }
    // tmp 拷贝回A[left...right]
    for(int i = 0; i < right-left; i++) {
        arr[left+i] = tmp[i];
    }
}

```

## 88. Merge Sorted Array

倒着来填写，哪个大就放后面

o(m+n)

o(1)

## 56. Merge Intervals

o(nlogn)

o(logn) - o(n) 排序需要的额外空间

## 57. Insert Interval

分成三种情况

o(n)

o(1)

## 75. Sort Colors

这里套一种排序算法即可

我这里套了快排 

o(nlogn)

o(logn)

## 147. Insertion Sort List

就是普通的比较和插入

O(n^2)

O(1)

## 148. Sort List

review : 自底向上的归并排序

https://www.youtube.com/watch?v=M1TwY0nsTZA

## 179. Largest Number

这个就是特殊排序

nlogn 

o(logn) ##  sort 空间复杂度

## 问题 STL sort如何实现

https://zhuanlan.zhihu.com/p/36274119

https://feihu.me/blog/2014/sgi-std-sort/

## 242. Valid Anagram 01 

这道题可以用个map去装，当如果字母数量相同，必然有一个会减到<=0

O(n)


O(S)  -- > O(1)

空间复杂度：O(S)，其中 SS 为字符集大小，此处 S=26S=26。



## 242. Valid Anagram 02 排序

nlog(n)

o(logn)

## 274. H-Index

o(nlogn)

o(logn)

## 581. Shortest Unsorted Continuous Subarray

先排序，然后比较

todo: 这里可以有更好的办法

o(nlogn)

o(n)

## 49. Group Anagrams

因为异构词，肯定sort后是一样的，sort后作为key，然后加入value的vector中

o(nklogk)

o(nk)


## 剑指 Offer 51. 数组中的逆序对 01 归并

## todo

https://blog.csdn.net/chch1996/article/details/106002600

21 1 47 148 

https://github.com/gaochengcheng/LeetCode/blob/master/LeetCode%E5%88%B7%E9%A2%98%E7%AC%94%E8%AE%B0%EF%BC%88%E6%8E%92%E5%BA%8F%E9%83%A8%E5%88%86%EF%BC%89.md