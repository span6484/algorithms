## 7. Reverse Integer

/ 和 % 的基本方法

o(n)  -- o(logx)

o(1)

## 9. Palindrome Number

换成string 然后双指针

o(n)  -- o(logx)

o(1)

## 633. Sum of Square Numbers 01 sqrt

如果是暴力枚举，O(N*N)，但是没必要，因为是平方，所以枚举到sqrt(c)即可

这里一个小trick判断是否开平方

```cpp
double b = sqrt(c - a*a);
if(b == (int)b) {
    return true;
}     
```

注意这里int可能会溢出

O(sqrt(c))

o(1)

## 633. Sum of Square Numbers 02 双指针

思考一个问题 ： 为何能够找到所以情况

什么 low*low+high*high < c 时，要让low++而不是high++呢？或者说为什么让low++可以保证不错过正确答案呢？

想象成一个棋盘搜索的过程，要么向左，要么向下


