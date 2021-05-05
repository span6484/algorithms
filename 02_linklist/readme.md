## leetcode linked list

1. 翻转链表问题

模板 见206题

2. 链表双指针解决问题


## 追逐者起点要先一步next

## 707 Design Linked List

malloc 和 calloc 之间的不同点是，malloc 不会设置内存为零，而 calloc 会设置分配的内存为零。

node struct 

list struct 

list 的构造初始化

get():一样的核心管用手段,用一个指向head的指针,一个一个next遍历去判断

addAthead():就是指向head，然后把head给他

addAtTail():遍历到最后去指向，注意如果head为NULL，直接把head给他

addAtIdx():遍历到index前面那一个，然后插入(注意inx=0的时候)

delAtIdx():同理判断在头上的时候，直接给下一个head地位，其他的一定要判断是否为NULL,否则next会出错的

listFree():这里需要一个tmp来指向free，cur拿来做遍历


# Be careful to check whether the head is NULL!!!

## 链表中的双指针

给定一个链表，判断链表中是否有环？

利用快慢指针，如果没有环，快指针将停在链表的末尾。

如果有环，快指针最终将与慢指针相遇。

问题：这两个指针的适当速度应该是多少？

## 141. Linked List Cycle 01 快慢指针

一般来说链表常见判断:

```c
if(head == NULL || head->next == NULL) {
    return false;
}
```

Time O(n)

space o(1)


## 142 Linked List Cycle II 01 快慢指针

A ---- x ----> B   ----- y ------> c  
     
               < --------- z -----

2*(x + y ) = x+y+ n(y+z)

x + y = n(y+z) 

x = z + (n-1)(y+z)

所以把将fast放到A,slow放到B，``相同速度``再走一次，相遇的地方就是那个节点

O(N)

O(1)

## 160 Intersection of Two Linked Lists 

- solution1:

先遍历看长度，然后取短的遍历比较

- solution2:双指针

前面是做减法，这里是做加法，当到了末尾就到另一个脑壳上，这样相加长度就是相等的

这个方法有点小巧妙，注意他不会进入死循环，他会一起到NULL然后相等结束

O(M+N)

O(1)

## 19 Remove Nth Node From End of List    

- solution 1 

这个是经过两次遍历的，第一次先求出总长度

注意判断 len == n 的情况，直接把脑壳给下一个

其他的就是遍历到前一个上面，指向next next

- solution 

one pass 做法,用一个在指针前面探路


O(L)

O(1)

## 小结

1. 在调用 next 字段之前，始终检查节点是否为空。

获取空节点的下一个节点将导致空指针错误。例如，在我们运行 fast = fast.next.next 之前，需要检查 fast 和 fast.next 不为空。

2. 仔细定义循环的结束条件。

## 复杂度分析

如果只使用指针，而不使用任何其他额外的空间，那么空间复杂度将是 O(1)

算法的时间复杂度总共为 O(N)

## 反转链表

一种解决方案是按原始顺序迭代结点(一个一个移动到脑壳上去)

复杂度为 O(N),空间复杂度O(1)


## 206. Reverse Linked List 01 迭代

把指针反向指就可以了，需要三个指针，pre、cur、next

先保存前一个节点，再将当前节点的next指针设为前一个结点, 依次往后移动

T O(N)

S O(1)

## 	206	Reverse Linked List 02 递归

T O(N)

S O(N)

## 203. Remove Linked List Elements

因为这道题如果是遇到了值为val,那么用上一个结点链接下一个结点。

所以我们干脆给个虚头，每次都存前一个结点，用cur->next->val去判断，然后用当前结点去链接就是了

注意如何给struct malloc:

```c
struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
```

链表一定要注意，有->next一定要判断当前是否为空

## 328. Odd Even Linked List 01 

这道题就是设置一个odd 指向 head, even 指向 head->next

只要有2个及其以下结点都可以直接返回

当odd和even的next都不为空的时候，xx->next = xx->next->next，跳着链接

注意这里需要设置一个head2存储even的首地址，最后链接上就行了

一定注意每次跳连了之后，指针也要移动到下一个结点

分析时候，奇偶两种情况一起分析，其实是统一的while判断

T O(N)

S O(N)

## 328. Odd Even Linked List 02

T O(N)

S O(1)

## 234. Palindrome Linked List 01 02 

总体思路，先用快慢指针找到中点，然后将后半段翻转，然后进行遍历比较。

注意几点

1. 空的链表设置是回文

2. 注意快慢指针使用

3. 翻转链表，需要tmp存下一个，prev存上一个，然后一个start遍历到最后一个，注意最后头要连下prev

O(N)

O(1)

# 双链表

多一个prev指针

## 21. Merge Two Sorted Lists

核心思想有个pre穿针引线，很巧妙

这道题思路很简单，比较哪个小就连过去，然后指针移动到下一格

这里需要注意的是两点，一点是最后判断NULL的时候直接指向另一个指针续上

最为重要的一点，指针要指向有位置的结点，不能指向空！！！！！

## 2. Add Two Numbers

注意链表是一个结点一个结点生成链接，不像数组那样生成一坨，一定要挨着挨着初始化next指针为NULL

https://zhuanlan.zhihu.com/p/85504177 复习下

## 430. Flatten a Multilevel Doubly Linked List 

我们这里就是一直往下走，如果遇到child，就把整个插入进来，然后因为这个是有很多层的，我们很容易想到递归，遇到子节点就往下溯插入即可。

## 430. Flatten a Multilevel Doubly Linked List 02 dfs 

首先走child，然后走next 

然后因为走child之后，然后child指针要清空，head->next就变成child了，所以要提前存储

prev每次随着变换，但在变换之前，先和之前的prev连接好

O(n)

O(N)

## 138. Copy List with Random Pointer 01

我们这里有个核心函数是返回random那个指针结点连接的index，然后再第二个深度复制的链表上将对应index的元素连接上。

我们第一次先将这些元素深拷贝，然后再考虑random指针的问题，这样会带来很多次重复的查找，效率并不好。所以考虑更好的解法。

## 138. Copy List with Random Pointer 02 

这种对应关系用个hashmap再好不过了(不过这里感觉没提升啥效率？但是理论上这种更方便查找)

复习map and unordered_map

我们在这里可以把建立表和建立结点合在一步，如果我们已经存入表了，就返回对应新list的结点，如果没有的话就生成新结点，将对应关系入表，然后next和random都这样递归下去连接

## 138. Copy List with Random Pointer 03

这里有个巧妙的方法，先将每个节点复制插入，然后random就是原节点random的下一个，连好random后再分离出来。

## 138. Copy List with Random Pointer 04

第一次先创建节点，没用管random, 但这个时候，用个unordered_map 将两个地址映射

第二次走的时候就是通过map将random连上

O(N)

O(N)

## 61. Rotate List

这道题其实很简单，就是算出需要最后几个丢到前面去


## 92. Reverse Linked List II 01 

返回倒序题，简单的记录主要连接的点，和reverse链表一样用三个指针一步一步往后移

o(n)

o(1)

## 143. Reorder List 01 

拿个unordered_map去存下标和list地址

O(n)

o(n)
