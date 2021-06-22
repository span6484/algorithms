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

## 724 Find Pivot Index 02 

这里就是先求出total，然后左侧是sum，pivot index左右要是相等的，则2*sum + nums[i] == total才行，否则无

O (N)

O (1)
 
## 35. Search Insert Position 01 

当找到的时候，返回index

第一次遇到比target大，那也就是这个index

当最后都没有，就是nums多一个位置的地方

O(n)

o(1)

## 56. Merge Intervals 01 

先排序， 其实默认的就是对index = 0 排序

然后遍历，当还没有数组或者记录的左侧区域最右小于当前区间的最左侧，直接放入

否则，肯定有重合，看哪个是在最右侧的，那么就直接移动右侧区间到最右侧

O(n)

o(n)

## 01.07. Rotate Matrix LCCI 01

这里有个简单的思想就是用翻转替代旋转

先上下折叠翻转，然后对角线翻转

O(N*N)

O(1)

## 01.08. Zero Matrix LCCI


用set去重

用一个set存需要清零的横坐标，一个存纵坐标

O(n*n)

o(n)

## 498. Diagonal Traverse 01 

 


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

## 498 Diagonal Traverse 01 

方向分奇偶

even：

last col: down (i+1,j)

1st row : right (i,j+1)

other: right up(i-1,j+1)

odd:

last row: right(i,j+1)

1st col: down(i+1,j)

other: left down(i+1,j-1)

## 498 Diagonal Traverse 02

O(N*N)

O(1)

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

O(M*N)

O(1)

## 28. Implement strStr() 02 kms 有限自动机法

套模板

O(M+N)

O(M)


## 14. Longest Common Prefix

如果strSize == 0 的话，直接就返回""就行了

## 14. Longest Common Prefix 02 

因为如果说有最长的公共前缀，那么第一个一定有

所以以第一个为基准去遍历，当后面的比他短或不同，直接返回substr

O(M*N)

O(1)

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

## 151. Reverse Words in a String 01 

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

## 151. Reverse Words in a String 02

总体思路，先将整个的reverse，然后读到不为空的时候，开始读单词再reverse，读完后加上空格，继续读下一个

所以最后那个多了个空格最后要erase掉

双指针去标记单词index

O(N)

O(1)

## 557. Reverse Words in a String III

此题快慢指针吃到一个空格就翻转，注意最后一次另外翻转就行

或者加一个trick,先给最后添加一个" ",然后最后去掉就可了

O(N*N)

O(1)

## 26. Remove Duplicates from Sorted Array 01 02 

这道题就是一个快慢指针，一个往前探路和之前的比较然后决定是否向前还是装到前面的框框

O(N)

O(1)

## 26. Remove Duplicates from Sorted Array 03 


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

## 5. Longest Palindromic Substring 01 

这里的一个奇偶小技巧，(len+-1)/2

(4-1)/2 = 1

(3-1)/2 = 1

回文有两种中间情况，一种是单，一种是双。 xxaxx. xxaaxx

遍历每一个当作中心点，然后求出他们最长的回文长度

记录最长的那个，求出它的start就可以求substr了

O(n*n)

o(1)

## KMP 算法

kmp - 有限自动机 框架 

```cpp
// O(M+N)
// o(M)
void build(const string& pat) {
    int m = pat.size();
    dp.resize(m);
    for (int i = 0; i < m; ++i){
        dp[i].resize(256);
    }
    dp[0][pat[0]] = 1;
    int x = 0;
    for(int i = 1; i < m; i++) {
        for(int ch = 0; ch < 256; ch++) {
            if(pat[i] == ch) 
                dp[i][ch] = i+1;
            else 
                dp[i][ch] = dp[x][ch];
        }
        x = dp[x][pat[i]];
    }
}

int search(string txt, string pat) {   
    if(!pat.size()) return 0;
    int m = pat.size();
    int n = txt.size();
    build(pat);
    int state = 0;
    for(int i = 0; i < n; i++) {
        state = dp[state][txt[i]];
        if(state == m) return i - m + 1;
    }
    return -1;
}

```

思路就是先去用pattern构建有限状态机

每一个字符都会对应一个状态，遇到一个字符跳转

当字符和我需要的相等，我的这个点的下一个状态就是i+1，否则我利用上个节点x去看

注意x的更新，是个shadow variable,他其实就是求最大的共同前后缀，然后从这里继续开始看下面的状态，就不用再重复前面的状态观察

## 周期字符串问题

https://writings.sh/post/algorithm-repeated-string-pattern

## 459. Repeated Substring Pattern

s+s,去掉首尾两个元素，如果s仍是子串，那么s就是周期字符串

注意这里256要超时，如果只是字母的话128即可

O(m+n)

O(128m)

## 459. Repeated Substring Pattern 02 

利用string的find

从index = 1 开始，如果最后找到就从size开始，说明完全和第二个重合，那么就不是


## 153. Find Minimum in Rotated Sorted Array 01 

因为它之前是有序的，所以当我们变小，那就是最小的点

否则就是第一个

o(N)

O(1)

## 153. Find Minimum in Rotated Sorted Array 02 二分

如果说当中间点大于最右边，那么说明rotate后，最小的去了右边，那么left = mid+1

反之right = mid 

因为有序，所以很容易想到二分查找使得时间复杂度变为LOGN

o(logN)

O(1)

## 121. Best Time to Buy and Sell Stock 01 

双指针不断移动，不断更新和最小值的差

O(N)

O(1)

## 滑动窗口问题

## 3. Longest Substring Without Repeating Characters 01

先用简单粗暴的办法，我们从左往右一个一个开始扫描

用一个unordered_map已经检查过的字符，当重复就结束，记录做大值

0 <= s.length <= 5 * 10^4 大概O(N*N) 处理10*8 - 9 次方，这里可能够呛

但是我们这里是s consists of English letters, digits, symbols and spaces. 内循环最多128个

所以 

O(128 * N)

O(128 * N)

## 3. Longest Substring Without Repeating Characters 02

slide window法

详细参考花花酱的表

https://www.youtube.com/watch?v=LupZFfCCbAU

14：45

Time complexity: O(n)

Space complexity: O(128)

NOTES: 长度为n的字串个数为N*N个

## 3. Longest Substring Without Repeating Characters 03

slide window 模板

模板最为重要是寻找counter的含义, 比如说3题, 他的窗口终止条件是遇到相同的字符,所以遇到counter++,当大于0就说明有重复的

所以遇到counter > 0 的情况就左边收缩

O(N)

O(128)


## 模板

For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions. A general way is to use a hashmap assisted with two pointers.



```cpp
int findSubstring(string s){
    vector<int> map(128,0);
    int counter; // check whether the substring is valid
    int begin=0, end=0; //two pointers, one point to tail and one  head
    int len; //the length of substring
    int head = 0;   // 寻找substring需要找个记录

    for() { /* initialize the hash map here */ }

    while(end<s.size()){
        if(map[s[end]] ? ) {  // 看规则
             /* modify counter here */
        }
        map[s[end]]--;  // 看规则
        end++;

        while(/* counter condition */){ 
            1. /* update len and head here if finding minimum*/
                    
            if(map[s[begin]] ?){ 
                /*modify counter here*/ 
            }
            //increase begin to make it invalid/valid again
            map[s[start]]++;
            start++;
        } 
        2. /* update len and head here if finding minimum*/
    }
    return len == ? "" : s.substr(head, len);
  }

```

One thing needs to be mentioned is that when asked to find maximum substring, we should update maximum after the inner while loop to guarantee that the substring is valid. On the other hand, when asked to find minimum substring, we should update minimum inside the inner while loop.

## 15. 3Sum 01 hashtable

虽然是三个数，我们只需要两个就能用hashtable去判断第三个有没有，注意去重操作

O(N^2)

O(N)

## 15. 3Sum 02 2 ptrs

## 再谈滑动窗口

时间复杂度是 O(N)

```cpp
int left = 0, right = 0;

while (right < s.size()) {`
    // 增大窗口
    window.add(s[right]);
    right++;

    while (window needs shrink) {
        // 缩小窗口
        window.remove(s[left]);
        left++;
    }
}
```

```cpp
/* 滑动窗口算法框架 */
// 两个 ... 处的操作分别是右移和左移窗口更新操作，操作是完全对称的
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0; 
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...  

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        /********************/

        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```
 
## 1423. Maximum Points You Can Obtain from Cards 01 滑动窗口

左右去拿最大，那么中间这些就要最小，刚好用一个窗口去滑动

o(n)

o(1)

137. Single Number II 01 

O(N)

O(n)

137. Single Number II 02 bit

注意这里的trick

sum += ((num >> i) & 1);  // 第i位求和

res |= (1 << i); 求余

o(32n)

o(1)

## 690. Employee Importance

就是拿个map去对应，

O(n)

o(n)

## 45. Jump Game II 01

每次找到能跳最远的区间，在这step++,然后再这个区间里找到下一个最远的区间

o(N)

O(1)

## 11. Container With Most Water 01 2ptr

为什么双指针就能不漏掉所有情况呢

直观的想:

左边是3, 右边是7，左边移动的话，可能会增大，不确定

而移动右边，左侧3是天花板了，可能还会下降

o(n)

o(1)

## 1720. Decode XORed Array

o(n)

o(1s)

## 1486. XOR Operation in an Array

o(N)

o(1)

## 31. Next Permutation

1. 在尽可能靠右的低位进行交换，需要从后向前查找

2. 将一个 尽可能小的「大数」 与前面的「小数」交换。比如 123465，下一个排列应该把 5 和 4 交换而不是把 6 和 4 交换

3. 将「大数」换到前面后，需要将「大数」后面的所有数重置为升序，升序排列就是最小的排列。以 123465 为例：首先按照上一步，交换 5 和 4，得到 123564；然后需要将 5 之后的数重置为升序，得到 123546。显然 123546 比 123564 更小，123546 就是 123465 的下一个排列

再举个例子

1　　2　　7　　4　　3　　1

下一个排列为：

1　　3　　1　　2　　4　　7

那么是如何得到的呢，我们通过观察原数组可以发现，如果从末尾往前看，数字逐渐变大，到了2时才减小的，然后再从后往前找第一个比2大的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：

1　　(2)　　7　　4　　3　　1

1　　(2)　　7　　4　　(3)　　1

1　　(3)　　7　　4　　(2)　　1

1　　3　　(1)　　(2)　　(4)　　(7)

o(n)

o(1)w

## 55. Jump Game 01

就是不断扩展最右边界

o(n)

o(1)

## 48. Rotate Image

所有旋转都能转化为翻转来做

o(n^n)

o(1)

## 621. Task Scheduler 01s

先统计频率，得到最高频率K，说明有K组，最后一组不加ide

所以前面k-1组，每一组长度n+1

如果不够就自动算添加idle

最后再加一轮

如果这样还小于总task数，说明间隔不够，全部都可以填满，不需要加idle

o(n)

o(1)

## 647. Palindromic Substrings 01 

循环每一个位当中间位，然后去左右拓展

O(n^n)

o(1)

## 560. Subarray Sum Equals K

suffix and unordered_map

todo

O(n)

O(n)

## 448. Find All Numbers Disappeared in an Array 01

就是先用一个set去存入1-n

然后通过num去erase

剩下没erase掉的肯定就是没有的

O(logn)

O(n)

C++ STL中各种数据结构操作的时间复杂度比较:

https://blog.csdn.net/dieju8330/article/details/108551007

## 448. Find All Numbers Disappeared in an Array 02

每个数组+n

如果哪个数组没有 > n，说明这个下标没有被轮到，就是缺的

o(n)

o(1)

## 394. Decode String

o(n)

o(n)

## 217. Contains Duplicate 01

用个map去记录，

o(n)

o(n)

## 103. Binary Tree Zigzag Level Order Traversal

就是选择deque这个数据结构的妙用

o(n)

o(n)