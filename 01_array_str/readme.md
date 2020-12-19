## leetcode array and str

## overview

了解数组和动态数组之间的区别

熟悉数组和动态数组中的基本操作

理解多维数组并能够掌握二维数组的使用

明白字符串的概念以及字符串所具有的不同特性

能够运用双指针技巧解决实际问题。

## 数组简介

数组和动态数组之间有什么不同？

在你常用的语言中，数组和动态数组对应的内置数据结构是什么？

如何在数组中执行初始化、数据访问、修改、迭代、排序等基本操作？

如何在动态数组中执行初始化、数据访问、修改、迭代、排序、添加、删除等基本操作？

## 724 Find Pivot Index

## 747 Largest Number At Least Twice of Others

## 66 Plus one 

步骤：

先分配一个 digitsSize + 1 的数组

先将第一个设置为1

倒着判断，如果为9，则变为0（这里因为是+1，所以我考虑复杂了）否则的话直接+1就break了，后面肯定不会受到影响

直接判断digits首位是否是0就知道他有没有超位了

直接将后面digitsSize位填入，判断digits首位是否为0来返回

## 二维数组

- 一定要首先去判断二维数组是否为空的情况！

## 498 Diagonal Traverse

方向分奇偶

even：

last col: down (i+1,j)

1st row : right (i,j+1)

other: right up(i-1,j+1)

odd:

last row: right(i,j+1)

1st col: down(i+1,j)

other: left down(i+1,j-1)

## 54. Spiral Matrix

用四个变量标志top,down,left,right来标志走到位置，不断的重复以下过程

left -> right top++

top -> down right-- 

right -> left down-- 

down -> top left++

注意他可能在中途断掉，所以每个遍历当行单列小循环后才判断是否装完了returnSize个

## 118. Pascal's Triangle

此题注意如何malloc

先申请二维，其中装的都是numRows个一维指针，

再给col array里面申请numRows个盒子装列数

然后遍历申请每一层的个数，然后装入相应的col个数

首尾先赋值1，注意允许连等

然后找个三角的规律非常简单，(i,j) = (i-1,j-1)+(i-1,j)

此时注意只用算一半，因为是对称的。

## 字符串

我们可以用 “==” 来比较两个字符串吗？

awnser:

我们使用的语言是否支持运算符重载？cpp可,java不可

- 是否可变

某些语言（如 C ++）中，字符串是可变的。 也就是说，你可以像在数组中那样修改字符串。

在其他一些语言（如  Java）中，字符串是不可变的。 此特性将带来一些问题。 我们将在下一篇文章中阐明问题和解决方案。

- 额外操作
 
了解这些内置操作的时间复杂度。

如果字符串的长度是 N，那么查找操作和子字符串操作的时间复杂度是 O(N)。

## 67. Add Binary

利用逆向遍历

先判断是否为空、内容为空，直接返回对方就可

记录标记位，将标记位与两个字符串的对应位相加，分析和，确定当前位的值和是否需要进位

求出两个str的长度，将最长的+2(一个留给进位，一个留\0,一定注意C语言的末尾跟\0)

注意这里有一个小trick，2进制进位: flag = (a[i] + b[i] + flag) / 2

memcpy使用

C 库函数 void *memcpy(void *str1, const void *str2, size_t n) 从存储区 str2 复制 n 个字符到存储区 str1


## 28. Implement strStr()

首先判断如果needle是""，则直接返回0

如果needle都大于haystack，那就直接返回-1

注意比较的时候，循环直接到haystack - needle处就行了

## 14. Longest Common Prefix

如果strSize == 0 的话，直接就返回""就行了

## 双指针技巧 - 情景一

反转数组

经常在排序数组中使用。

两边往中间夹逼

## 344. Reverse String

这个直接套用双指针的模板

```cpp
void reverse(int *v, int N) {
    int i = 0;
    int j = N - 1;
    while (i < j) {
        swap(v[i], v[j]);
        i++;
        j--;
    }
}
```
## 561. Array Partition I

一种贪心解法，将相近的放一起，这样min损失的小点

先排序，再跳着加就行了

## 167. Two Sum II - Input array is sorted

- solution 1 

暴力法

这里注意如果两个数都大于target那就没必要继续往下走了

- solution 2

双指针法,O(n),两边夹逼
## 双指针技巧 —— 情景二

不同步的两个指针

给定一个数组和一个值，原地删除该值的所有实例并返回新的长度。

## 27. Remove Element

这道题直接套模板就好了

## 485. Max Consecutive Ones

第一个指针设置在-1，其实就是求两个0之间的距离，注意后面还有到结尾的一段

# 209. Minimum Size Subarray Sum

就是一个双指针滑窗思想

189. Rotate Array

注意取余移动

左边先reverse,右边移动的再reverse，然后总体reverse

119. Pascal's Triangle II

直接使用组合公式C(n,i) = n!/(i!*(n-i)!)

则第(i+1)项是第i项的倍数=(n-i)/(i+1);

这里就是注意计算过程乘的部分可能超出int的范围，要用一个long来转换类型

151. Reverse Words in a String

一定注意判断是否为空等特殊情况！！！

这里前中后的空格处理

前面直接吃，后面直接填0就可

中间的空格我为了只遍历一次，我就分三种情况

空空

空x

空0

如果是空空，快指针继续往后走

如果是空x，慢指针位置添加快指针位置的东西，相当于添加空

空0的话，继续往后走，这里就是相当于结束了循环

如果不是空格，那么就把慢指针位置添加快指针位置的东西

这里我们顺便要进行翻转，start是按照第一次空X的X来更新

end就是第一个cur-1，所以我们判断现在指向空格的前一个是否为空，不为则是第一个，那么就是end，翻转

最好翻转后判断最后一个是否空结尾，如果不是的话，我们最后一个单词是没有翻转的

然后翻转整体添加str的结尾就完事儿了

557. Reverse Words in a String III

此题快慢指针吃到一个空格就翻转，注意最后一次另外翻转就行

26. Remove Duplicates from Sorted Array

这道题就是一个快慢指针，一个往前探路和之前的比较然后决定是否向前还是装到前面的框框

283. Move Zeroes 01

这道题我用了个快慢指针，然后慢指针吃0，快指针吃非0，遇到之后就交换，有点burger

283. Move Zeroes 02

之前那个burger是因为，直接用快指针吃非0填充前方就是了，其他补0就完事了




## problem 

variable-sized object may not be initialized?

C语言规定了不能使用variable-sized的数组

使用变量定义长度时，不可在定义时同时进行初始化赋值，需要在之后进行赋值

# 注意二维数组作为形参的时候！！！

二级指针传入参数规则

1. 当二级指针作为函数形参时，能作为函数实参的是二级指针，指针数组，一级指针的地址

2. 当指针数组作为函数形参时，能作为函数实参的是二级指针,指针数组,一级指针的地址

3. 当数组指针作为函数形参时，能作为函数实参的是二维数组，数组指针

4. 当二维数组作为函数形参时，能作为函数实参的是二维数组，数组指针

- 总结：1，2相同，3，4相同

见2_rd_ptr.c

# 二级指针初始化

```c
//分配一个3*3大小
int cnt=0, i, j; 
int **pp = (int**)malloc(sizeof(int*) * 3);
for(i = 0; i < 3; i++){
    *(pp+i) = (int*)malloc(sizeof(int) * 3);
    for(j = 0; j < 3; j++)
        pp[i][j] = ++cnt;
}
```

## 122. Best Time to Buy and Sell Stock II 01 贪心

遍历整个股票交易日价格列表 price，策略是所有上涨交易日都买卖（赚到所有利润），所有下降交易日都不买卖（永不亏钱）

时间复杂度 O(N)O(N) ： 只需遍历一次price；
空间复杂度 O(1)O(1) ： 变量使用常数额外空间



