## 解体模板

https://zhuanlan.zhihu.com/p/112926891

关键词 ： return all 

```cpp
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```

## 131. Palindrome Partitioning 01 
 
全局变量：该题目要找到可分割的方案，最终结果形式上是：vector<vector<string> >
参数设计：（1）状态变量：当前是回文的字符串（2）条件变量：剩余待搜索的字符串，当字符串长度为0，则搜索完毕。
完成条件：剩余字符串长度为0。
递归过程：在剩余字符串中遍历，如果该串为回文 就 进入下次递归，如果非回文 就 继续搜索下一个串。

总共有 2^(n − 1) 种划分方案。另外对于每个方案，需要 O(n)的时间记录和判断是否回文方案。所以总时间复杂度是 O(2^n * n)

空间复杂度为 O(n)

## 40. Combination Sum II 01 

全局变量：res = []
参数设计：（1）状态变量：当前选用过的数字（2）条件变量：剩余的起始位置 和 剩余需要凑的数字
完成条件：当剩余0，就加入到res；当小于0，则不再搜索；
递归过程：如果当前剩余大于0就继续搜索。

注意如何去重

1. 首先排序

2. 重复的留到下一个递归里取，而不是开头取则重复

3. 每次i+1就是有序的，不会有无序相同组合

O(2^n * n)

O(n)
  
## 90. Subsets II 01 

和40大概相同，就是要去重，但是要简单一点，因为他是找出所有的可能

所以没有各种终止条件

O(2^n * n)

O(n)

## 46. Permutations 01

按照模板，一般是需要一个state取push，pop，然而全排列只是变化顺序

每次第一步选了之后就无法往前选，所以我们这里巧妙运用了swap即可

对于 backtrack 调用的每个叶结点（共 n!n! 个），我们需要将当前答案使用 O(n)O(n) 的时间复制到答案数组中，相乘得时间复杂度为 O(n \times n!)O(n×n!)。

O(N*N!)

O(N)

## Offer 38. 字符串的排列 01

其实在每一个backtrace里都是一步，要进行下一步就递归下去，所以去重就在当步不选已经选过的

所以最简单的办法每一步用个unordered_set去记录

O(N*N!)

O(N)

## 93. Restore IP Addresses

全局变量：res = []

参数设计：（1）状态变量：当前组成的IP分割形式（2）条件变量：剩余字符idx 和 已组成的IP节个数。

完成条件：如果剩余的字符不能拼成一个IP，则返回；如果没有剩余字符，就加入到res。

递归过程：当前 字符 为一个合法IP节，则加入当前元素进入下一次递归。

遇到的错误是：全局有可能会改变

最后那个.最后的时候pop back再加入

O(3^3)，因为每个.号的插入位置都可以有三种选择

O(1)

## 996. Number of Squareful Arrays

这个和去重全排列的题一样，不过多了一步判断是否是平方数

```cpp
bool isSquare(int num) {
    int m = sqrt(num);
    if(m*m == num) return true;
    else return false;
}
```
O(N!)

O(N)

## 1239. Maximum Length of a Concatenated String with Unique Characte 01

判断一个string是否有重复字母

```cpp
bool hasDuplicate(const string& str) {
    unordered_set<char> s(str.begin(), str.end());
    if (s.size() != str.length()) 
        return true;
    return false;
}
```

state以参数形式不用手动回退

每次加了先判断是否有重复再加入下一个的选择

不走回头路，因为没顺序问题

时间复杂度：O（2 ^ n）

空间复杂度：O（n）

全局变量：int maxLen，这里是要最长长度，不需要字符串组成结果

参数设计：（1）状态变量：已经使用的字符串（2）条件变量：剩余的字符串。(idx)

完成条件：如果当前的长度大于已搜到的最大长度，则更新maxLen 。

递归过程：当前字符串和已有字符串没有重复元素，则进入下次递归。

## 306. Additive Number



## todo

https://zhuanlan.zhihu.com/p/112926891