## leetcode linked list

了解单链表和双链表的结构；

在单链表或双链表中实现遍历、插入和删除；

分析在单链表或双链表中的各种操作的复杂度；

在链表中使用双指针技巧（快指针慢指针技巧）；

解决一些经典问题，例如反转链表；

分析你设计的算法的复杂度；

积累设计和调试的经验。

## 单链表

与数组不同，我们无法在常量时间内访问单链表中的随机元素。 如果我们想要获得第 i 个元素，我们必须从头结点逐个遍历。 我们按索引来访问元素平均要花费 O(N) 时间，其中 N 是链表的长度。

我们使用头结点来代表整个列表

## 添加操作 - 单链表

与数组不同，我们不需要将所有元素移动到插入元素之后。因此，您可以在 O(1) 时间复杂度中将新结点插入到链表中，这非常高效。

## 删除操作 - 单链表

我们需要找出 prev 和 next。使用 cur 的参考字段很容易找出 next，但是，我们必须从头结点遍历链表，以找出 prev，它的平均时间是 O(N)，其中 N 是链表的长度。因此，删除结点的时间复杂度将是 O(N)

空间复杂度为 O(1)，因为我们只需要常量空间来存储指针。

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

## 141. Linked List Cycle

一般来说链表常见判断:

```c
if(head == NULL || head->next == NULL) {
    return false;
}
```

这道题就是利用快慢指针

## 142 Linked List Cycle II

A ---- x ----> B   ----- y ------> c  
     
               < --------- z -----

2*(x + y ) = x+y+z

x = z 

所以把将fast放到A,slow放到B，``相同速度``再走一次，相遇的地方就是那个节点

## 160 Intersection of Two Linked Lists 

- solution1:

先遍历看长度，然后取短的遍历比较

- solution2:双指针

前面是做减法，这里是做加法，当到了末尾就到另一个脑壳上，这样相加长度就是相等的

这个方法有点小巧妙，注意他不会进入死循环，他会一起到NULL然后相等结束

## 19 Remove Nth Node From End of List    

- solution 1 

这个是经过两次遍历的，第一次先求出总长度

注意判断 len == n 的情况，直接把脑壳给下一个

其他的就是遍历到前一个上面，指向next next

- solution 

one pass 做法,用一个在指针前面探路

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

## 	206	Reverse Linked List    

- solution1 迭代法

把指针反向指就可以了，需要三个指针，preItem、currItem、nextItem

先保存前一个节点，再将当前节点的next指针设为前一个结点

然后当前节点就作为前一个节点，继续迭代

- solution2 递归法


## 203. Remove Linked List Elements

因为这道题如果是遇到了值为val,那么用上一个结点链接下一个结点。

所以我们干脆给个虚头，每次都存前一个结点，用cur->next->val去判断，然后用当前结点去链接就是了

注意如何给struct malloc:

```c
struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
```

链表一定要注意，有->next一定要判断当前是否为空

## 328. Odd Even Linked List

这道题就是设置一个odd 指向 head, even 指向 head->next

只要有2个及其以下结点都可以直接返回

当odd和even的next都不为空的时候，xx->next = xx->next->next，跳着链接

注意这里需要设置一个head2存储even的首地址，最后链接上就行了

一定注意每次跳连了之后，指针也要移动到下一个结点

分析时候，奇偶两种情况一起分析，其实是统一的while判断

## 234. Palindrome Linked List

总体思路，先用快慢指针找到中点，然后将后半段翻转，然后进行遍历比较。

注意几点

1. 空的链表设置是回文

2. 注意快慢指针使用

3. 翻转链表，需要tmp存下一个，prev存上一个，然后一个start遍历到最后一个，注意最后头要连下prev

# 双链表

多一个prev指针

## 21. Merge Two Sorted Lists

这道题思路很简单，比较哪个小就连过去，然后指针移动到下一格

这里需要注意的是两点，一点是最后判断NULL的时候直接指向另一个指针续上

最为重要的一点，指针要指向有位置的结点，不能指向空！！！！！

