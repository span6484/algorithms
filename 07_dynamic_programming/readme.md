## Dynamic programming 

## 模板

```cpp
// 递推

dp = ... # create dp array 
         # add padding if needed

dp[0][0] = #init dp array base cases

for i ...
    for j ...
    ...
        dp[i][j] = ... # transition

return dp[m][n]

// 递归

mem = ... # create mem dict 

def dp(i, j, ...):
    if base_case(i, j) : return 
    if (i, j) not in mem:
        mem[(i, j)] = ...  # transition
    return mem[(i,j)]

return dp(m,n)


```


## 


Fibonachi Sequence 

1 1 2 3 5 8 13 21

fib(n) = 1  n = 1 or 2

else 

fib(n) = fib(n-1) + fib(n-2)

overlap sub-problem

![fib](./assets/fib.png)

```cpp
int fib(int n) {
    if(n <= 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
```

```cpp
// 递推
f[0] = 1;
f[1] = 1;
for(int i = 2; i < n; i++) {
    f[i] = f[i-1] + f[i-2];
}
```

如果递归展开的话我们需要重新计算fib(5),复杂度为O(2^N),我们要想办法去利用之前的值

![fib_dp](./assets/fib_dp.png)

```cpp
int fib(int n) {
    if(n <= 1) {
        return 1;
    }
    if(result[n] >= 0) {
        return result[n];
    }
    return fib(n-1) + fib(n-2);
}
```

如此overlap sub-problem子问题就变成了O(N)的复杂度
![dp_0](./assets/dp_0.png)

![dp_1](./assets/dp_1.png)

## 198. House Robber 01 暴搜

暴力搜索一定是递归，这题用暴搜超时，但是体现了上述过程的思想，比较当前值+prev的递归和上一个值的递归，这样我们问题规模就越变越小了，虽然这道题超时，但是思路值得借鉴。

时间复杂度分析，因为最多可能要N次，每次有2种决策，所以O(2^N)

我们来分析优化：

n-1 -> (n-3, n-4, n-5 ....)

n-2 -> (n-4, n-5 .....)

其中有很多重复计算

我们希望if(算过) return 结果

![dp_2](./assets/dp_2.png)

QA:c++类成员变量初始化(unsolved)

https://zhuanlan.zhihu.com/p/118692769

## 198. House Robber 02 dp

根据我们上面分析，我们用一个数组存储已经算过的值就可了

因为每一个状态我们只用算一遍，我们的时间复杂度为O(N),空间复杂度为O(N)

![dp_3](./assets/dp_3.png)

![dp_4](./assets/dp_4.png)

## 198. House Robber 03 dp 迭代

将上面这个自顶向下的递归改为自底向上的迭代，这样边界判断和前面数字处理会多一点，但逻辑会更加清晰。

## 198. House Robber 04 dp 迭代 滚动数组

其实我们这里只需要前两次的房屋就可了，所以我们只需要两个变量来存就可

## 小兵向前冲

![dp_5](./assets/dp_5.png)

![dp_6](./assets/dp_6.png)

```cpp
// 暴力回溯
int f(int m, int n) {
    if(m == 0 || n == 0) return 0;
    if(m == 1 || n == 1) return 1;
    return f(m-1, n) + f(m, n-1);
}
```

## 64. Minimum Path Sum 01 dp

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

之前棋盘看多了，下意识左下是(0,0)了，这个是个很典型的dp问题，暴力的话，时间复杂度为O(2^N),我们这里状态转移方程为f(m,n) = min(f(m-1,n),f(m,n-1))+ grid(m,n).因为我们这里比较做小，边界条件超过的话就返回INT_MAX。时间复杂度是O(MN)，空面复杂度为O(MN)。

## 64. Minimum Path Sum 02 暴力

暴力超时，主要是可以得到状态转移方程，我们这里的时间复杂度为O(2^(M+N)),空间复杂度为O(M+N),因为递归的深度为M+N

## 64. Minimum Path Sum 03 二维dp 递推

这里我们建立一个二维的dp数组递推装最小的sum，我们先把最边缘的两边[0][j]和[i][0]给一路加上值，其他的是min(dp[i-1][j], dp[i][j-1]) + grid[i][j].这个是自底向上的递推。空间复杂度为O(M*N),时间复杂度为O(M*N)

## 64. Minimum Path Sum 03 递推，无需额外空间

因为这个只用遍历一次二维数组，所以我们不需要额外空间。

空间复杂度为O(1),时间复杂度为O(M*N)

## 01背包问题

![beibao_0](./assets/beibao_0.png)

```cpp
// 暴力法
int w[n], v[n], W;

// S <= W
int search(int idx, int S) {
    if(S > W) return 0;
    if(idx >= 0) return 0;
    return max(search(idx + 1, S+ w[idx]) + v[idx], search(idx + 1, S));
}
```

```cpp
int w[n], v[n], W;

int search(int idx, int S) {
    if(S > W) return 0;
    if(idx >= 0) return 0;
    if(f[idx][S] >= 0) return f[idx][S];
    f[idx][S] = max(search(idx + 1, S+ w[idx]) + v[idx], search(idx + 1, S));
    return f[idx][S];
}
```

```cpp
// 递推
f[0][0] = 0;
for(int i = 1; i <= W; ++i){
    f[0][i] = -maxValue;
}
for(int idx = 1; i <= n; ++idx) {
    f[idx][0] = 0;
    for(int j = 1; j <= W; ++j) {
        f[idx][j] = f[idx -1][j];
        if(j >= w[idx]) 
            f[idx][j] = max(f[idx-1][j - w[idx]] + v[idx], f[idx][j]);
    }
}
```

## 322. Coin Change 01 暴力

这里我们的状态就是两个，一种是选择search(idx, amount-coins[idx], coins)+1，一种是不选择search(idx-1, amount, coins)，直接进行到下一种面值不增加。

时间复杂度为O(2^(K*N))

## 322. Coin Change 02 dp 开二维数组备忘录

这里有点蠢，但是没得办法，这种暴力是有两种状态决定的，一种是amount，一种是面值，开了个 N* K大小的数组，因为N可能很大，这里时间复杂度就降为了O(N*K),空间复杂度为O(K*N)，但是这种的overlap问题也不是很好的解决，因为10分为了10(1),10(2),10(5).

## 322. Coin Change 03 另一种暴力

时间复杂度分析: 子问题总数 * 解决每个子问题的时间

这个多叉树的结点有(N^K)，相当于每一个都遍历一下，每一个子问题带有一个循环，所以时间复杂度为O(K*N^K)

## 322. Coin Change 04 上个暴力的dp

因为这里就一个变化量amount，所以我们开一个一维数组存mount状态，我们这里的时间复杂度为O(K*N)，空间复杂度为O(N)

## 322. Coin Change 05 递推1

应用DP框架：

```
# 初始化 base case
dp[0][0][...] = base
# 进行状态转移
for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 求最值(选择1，选择2...)
```

时间复杂度为O(K*N)，空间复杂度为(N)

https://www.cnblogs.com/grandyang/p/5138186.html

## 518. Coin Change 2 01 递归dp

这道题和coin 1 不同的是，如果是amount到最后等于0的话，就算成功的一次，然后两种情况相加而不是比大小，比大小的话就是求最大路径了

Time O(M * N)

Space O(M * N)

## 518. Coin Change 2 02 当成树遍历

## 746. Min Cost Climbing Stairs 01 暴力

肯定不能过，只是第一步找出暴力搜索，然后去优化

## 746. Min Cost Climbing Stairs 02 dp 递归

和其他dp一样，我们这里需要都遍历一次，时间复杂度为O(N),空间复杂度为O(N)。

这里我们遇到一个问题就是，我们最后一个是走还是不走，我们精妙的添加一个0，如果不走的话我们选到下一个阶梯就为0即可。

状态转移方程也是把大问题拆成小问题，将最小的前面方案加上当前。

## 746. Min Cost Climbing Stairs 03 递推

学会将递归改为递推，即自顶向下改为自底向上，()改为[]，边界条件。

时间复杂度，空间复杂度皆为O(N)

## 746. Min Cost Climbing Stairs 04 递推 滚动数组

只需要i-2 i-1即可，滑动过去，所以空间复杂度减为O(1)

## 70. Climbing Stairs 01 dp 递归


套路，一共多少，和上面coin Change2 类似，不过数值没有前后关系。

count就是相加

memo[i] = dp(i-1) + dp(i-2);

Time complexity O(N)

Space O(N)

## 70. Climbing Stairs 02 dp 递推

模板

Time  O(N)

Space O(N)

## 70. Climbing Stairs 03 dp 递推 滚动数组

模板

Time  O(N)

Space O(1)
 
# 线性DP 

线性 DP 问题是指递推方程具有明显的线性关系，有一维线性和二维线性。

https://www.cnblogs.com/grandyang/p/4938187.html

## 300. Longest Increasing Subsequence 01 dp

用一个dp数组存每个位置的串长最大值，第二重复循环走前面的值，如果小的话，就把最大长度和当前所存的长度比较，如果大就存下来，每次第二重循环走完后都要比较下当前是否为整个的最长。

深入理解看花花酱视频

https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-300-longest-increasing-subsequence/

空间复杂度为O(N),时间复杂度为O(N^2)

## 300. Longest Increasing Subsequence 02 二分

这里所求并不是要的递增数组，但是长度相同

总的核心思想就是，如果比最后那个大，就往后丢，增大窗口，其余的就去更新比他大的最小的那个。

这里学会了std::lower_bound

Time O(nlogn)

Space O(n)

## 300. Longest Increasing Subsequence 03 二分 简介版本

## 354. Russian Doll Envelopes 01 二分

这道题十分精妙

拓展成二维，但我们可以巧妙降维

我们先排序，第一个元素升序，第二个如果是第一个元素相同，我们降序，这样就可以避免我们把第一个相等取多次

这里学习了sort + lambda

其余和最大子序列相同
 
TIME O(nlogn) 排序和二分都是nlogn

Space O(N)

## 354. Russian Doll Envelopes 02 DP

巧妙地转化为了LIS问题，降成了一个维度

O(N * N)

O(N)


## 334. Increasing Triplet Subsequence 01 二分

最好 Time O(1)

最坏 Time O(nlogn)

Space O(1)

## 334. Increasing Triplet Subsequence 02 双重循环追逐

最坏 Time O(N*N)

Space O(N)

## 334. Increasing Triplet Subsequence 03 双指针

两个指针不断更新较小值，如果来了个比两个都大的，就是三个了，true

最坏 Time O(n)

Space O(1)

## 1143. Longest Common Subsequence 01 暴力搜索

一种有三种情况，第一种是匹配到，然后就继续同时往下走，还有一种是没有匹配赛，要么text1走，要么text2走。

注意边界条件为何x == -1 || y == -1 即可。

那么时间复杂度最坏为O(2^(M+N))

一个问题 

```cpp
if str1[i - 1] == str2[j - 1]:
    # ...
else:
    dp(i,j) = max(dp(i-1,j), 
                   dp(i,j-1),
                   dp(i-1,j-1))
```

不需要这样是为何，因为在dp(i-1,j-1)是最小的那个


## 1143. Longest Common Subsequence 02 dp 迭代

很明显他有两个状态，所以我们用一个二维memo来存储状态即可。

时间复杂度为O(M*N),空间复杂度为O(M*N)

## 1143. Longest Common Subsequence 03 dp 递推

还是应用框架即可。

时间复杂度为O(M*N),空间复杂度为O(M*N)

## 1143. Longest Common Subsequence 04 dp memory optimization

You may notice that we are only looking one row up in the solution above. So, we just need to store two rows.

time complexity O(M*N)

space complexity O(N)

## 1143. Longest Common Subsequence 05 dp memory optimization

我们开的空间在于第二重循环，所以我们将小的放进二重循环中。

time complexity O(M*N)

space complexity O(min{M,N})

## 1035. Uncrossed Lines 01 dp 递归 02 递推 03 内存优化

和1143完全一样，不相交，又要对应。本质就是最长子序列。

## 583. Delete Operation for Two Strings

这道题要求最少改变，其实就是减去最大子序列，求同存异，所以和1143一样。

## 516. Longest Palindromic Subsequence 01 dp

这道题也和最长子序列相同，我们就是求他和自身的逆序的最长子序列，就是最长的回文子序列。

时间复杂度为O(N*N)

空间复杂度为O(N)

## 516. Longest Palindromic Subsequence 02 

套路未状态压缩 

时间复杂度为O(N*N)

空间复杂度为O(N*N)

##  

## 1092. Shortest Common Supersequence

![1092](https://zxi.mytechroad.com/blog/wp-content/uploads/2019/06/1092-ep251.png)

这里的五种case很精妙，好好体会


## 96. Unique Binary Search Trees 01 dp recursion

Taking 1~n as root respectively:

    1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1

    2 as root: # of trees = F(1) * F(n-2) 

    3 as root: # of trees = F(2) * F(n-3)

    ...
    
    n-1 as root: # of trees = F(n-2) * F(1)
    
    n as root:   # of trees = F(n-1) * F(0)
 
    So, the formulation is:
    
    F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)


State transition equation：

for(int i = 1; i <= n; i++) {
    memo[n] += helper(i - 1) * helper(n - i);
}

TC : O(N^2)

Because 1 + 2 + 3 + ... + n = O(n^2)

SC : O(N)

## 96. Unique Binary Search Trees 02 dp iteration 

moban

TC : O(N^2)

SC : O(N)

## 122. Best Time to Buy and Sell Stock II 01


## 139. Word Break 01 dp

这道题就是用个unordered_map存取每一个sub字串能否去拼接

然后我们从中间去切割，每次就转换成了小问题

O(N*N)

O(N*N)

----------------编辑距离题型 -------------------


## 72. Edit Distance 01 DP

其实这道题思路非常简单

![72dp](https://zxi.mytechroad.com/blog/wp-content/uploads/2017/10/72-ep87.png)

如果l1为空，则为l2的长度，反之

如果最后一位相同，那么取前面l-1

比如 abbc, acc 那么就只看 abb 和 ac 

abb 到 ac分为三种

1.delete 2.insert 3.replace 

那么对应操作就说 (i-1,j) (i,j-1) (i-1,j-1)

取最小的+1

dp就是去把问题规模不断化小

o(l1 * l2)

O(l1*l2)

## 最大子数组和 问题

## 53. Maximum Subarray 01

递推core，思想就是如果前面的最大都小于0，那我没必要加他，如果大于01再加

memo[i] = memo[i-1] > 0 ? memo[i-1]+nums[i] : nums[i];

O(N)

O(N)

## 62. Unique Paths 01

路径问题 memo[m][n] = dp(m-1, n) + dp(m, n-1);

O(M*N)

O(M*N)

## 62. Unique Paths 02 

递推

## 926. Flip String to Monotone Increasing 01 

暴力法的话，分成两部分，左边全0，右边全1，然后去统计需要翻转的数

这样的复杂度为N^2, S.length 可达到20000,肯定超时，一般大于5k就不可了

一般要n or nlogn办法

这里就是空间换时间的思想

用两个数组，一个表示前n个全换成0需要翻转的个数，另一个反向计算全换成1

最后再遍历一次找相加之和

O(N)

O(N)

## 818. Race Car 01 BFS 见chapter 03

## 818. Race Car 02 dp 

trick : 需要移位的数字<<移位的次数n 

运算规则：按二进制形式把所有数字向左移动相应的位数，高位移出（舍弃），低位的空位补0。相当于乘以2的n次方

1 * 2^n : 1 << n

log2() 函数

分成三次情况

1. 刚好加速到

if((1 << n) == t+1) return memo[t] = n;

2. 先过了点然后返回

memo[t] = n + 1 + dp((1<<n)-1-t);

3. 提前一此返回再继续

for(int m = 0; m < n-1; m++) {
    int cur = (1<<(n-1)) - (1 << m);
    memo[t] = min(memo[t], n-1+1+m+1+dp(t-cur));
}

复杂度就是看有多少个子问题，每个子问题复杂度多少

子问题有t个，target

每个子问题，因为for循环的是t的对数

所以O(tlogt)

O(t + logt )

挺难想到

## 403. Frog Jump 

https://leetcode-cn.com/problems/frog-jump/solution/gong-shui-san-xie-yi-ti-duo-jie-jiang-di-74fw/

o(N^N)

o(n^n)

## 42. Trapping Rain Water

接水问题就是找左边最大的lmax,右边最大的rmax

取他们之间最小的减去当前的h  : max(lmax, rmax) - h

然而我们每次去扫描左右的话，那么复杂度o(n*n)

那么提前存好各个地方左右的最高

O(n)

o(n)