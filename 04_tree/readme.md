# 树的遍历

## 144. Binary Tree Preorder Traversal 01 递归

树的递归方法很套路，套用即可

## 144. Binary Tree Preorder Traversal 01 迭代(stack)

这里就是每次将右节点放入再看左节点

## 94. Binary Tree Inorder Traversal 01

递归套路

## 94. Binary Tree Inorder Traversal 02

递归是先把左边装到底然后慢慢push进来存值，然后每次取栈顶元素存值然后看他右侧，这样就是左 - 中 - 右的顺序

## 94. Binary Tree Inorder Traversal 03 Morris

Morris 遍历

其实就是一直在找前序后继，将其变线性

当左边没有，肯定当前就是最左边了，然后记录，往右走

如果左边有，那么当前的前序肯定在左边子树的最右。注意while语句判断。

然后把最右的子树的right连到当前，root往左更加细粒度

如果右边连了，那么直接恢复到nullptr，push记录，因为这里当前结点肯定是最左了，继续往右边子树走

Time O(n)

Space O(1)

https://www.cnblogs.com/anniekim/archive/2013/06/15/morristraversal.html


## 145. Binary Tree Postorder Traversal 01 递归

套路

## 145. Binary Tree Postorder Traversal 02 迭代

复习deque

这里非常巧妙的利用了deque，因为preoder是中左右，postorder是左右中，他的逆序是中右左，所以就很像前序的逆序，不过在装stack的时候先装左再装右，deque插入首非常高效，我们每次将它插入首然后给vector就是逆序了

## 102. Binary Tree Level Order Traversal 01 递归

这里的递归和前序一样，多了一个level来记录层，当前level大于等于res的size的时候，说明来到了新的层，我们添加一个层进来。

实际上前序，中序，后序都一样，因为他们都是从左往右的顺序。

## 102. Binary Tree Level Order Traversal 02 迭代

这里迭代的套路一样，就是用队列来装，但是这里需要每次记录每层的个数。

## 104. Maximum Depth of Binary Tree 01 递归

递归这里就很巧妙，递归就是一直递到下一层然后不断+1上来，然后回溯上去得到值，这里我们需要比较左右子树的最大值。

## 104. Maximum Depth of Binary Tree 02 BFS

其实我们这里和层次遍历相同 , 这也称为BFS

## 104. Maximum Depth of Binary Tree 03 DFS

这其实就是刚才讲的自顶向下的方法。

## 101. Symmetric Tree 01 双端队列

这里用了个双端队列，从front取一个和back取一个比较，如果一样的话 ，front先丢right再丢左，back先丢left再丢right。这样一直是对称着丢，而且肯定会遍历完的。

## 101. Symmetric Tree 02 队列

这样的就是先加两个root，每次就按着反向对应的顺序装入，每次pop两次来比较

## 101. Symmetric Tree 03 双队列

其实流程和02一样，只是双队列来装了而已 

## 101. Symmetric Tree 04 递归

每次递归还是和之前一样，左右对应

## 112. Path Sum 01 递归

见代码

## 112. Path Sum 02 迭代

queue一般用于BFS，stack一般用于DFS，我们这里用两个栈，一个存结点，一个存对应的需要的值，然后栈就是去DFS，去求出最后leaf是否满足条件。

# 重建二叉树

前序/后序+中序序列可以唯一确定一棵二叉树

# 105. Construct Binary Tree from Preorder and Inorder Traversal 01 递归

preorder的第一个就是根节点，我们根据没有重复这个遍历构造一个unordered_map可以找到inorder的root位置。

preorder : [[root], [左]，[右]] 

inorder : [[左],[root],[右]]

我们找到了inorder后，就可以分而治之。

## 106. Construct Binary Tree from Inorder and Postorder Traversal 01 递归

同105，不过他的root在最后一个元素。

## 116. Populating Next Right Pointers in Each Node 01 迭代

其实就是一个层次遍历，从右到左每次出列后给next指针赋值，tmp每次暂存上一次的值就可以实现连接了。

## 116. Populating Next Right Pointers in Each Node 02 递归

迭代法要用到queue，另需的空间是O(N)而不是constant，所以我们这里用递归，我们结束的判断条件是这个节点为空或者左节点为空，因为他是perfect tree所以不需要判断右边了，然后就是每个节点的左子树连上右子树，如果节点有next的话，我们还需要把当前节点右子树和下一个节点的左子树连上，然后移动到子树节点上递归。

## 117. Populating Next Right Pointers in Each Node II 01 递归

我们这里的情况分为，如果左右节点都有，左连右(右再连父节点下一个的子节点),如果只有左没有右，左直接连父节点下一个的子节点，不管有没有左，我们如果右存在的话，都用右去连。实现一个递归找next的函数。这里注意我们为何要先右递归再左递归。

// 先确保 root.right 下的节点的已完全连接，因 root.left 下的节点的连接
// 需要 root.left.next 下的节点的信息，若 root.right 下的节点未完全连
// 接（即先对 root.left 递归），则 root.left.next 下的信息链不完整，将
// 返回错误的信息。可能出现的错误情况如下图所示。此时，底层最左边节点将无
// 法获得正确的 next 信息：
//                  o root
//                 / \
//     root.left  o —— o  root.right
//               /    / \
//              o —— o   o
//             /        / \
//            o        o   o

## 236. Lowest Common Ancestor of a Binary Tree 01 递归

如果是为空为p和q的话就返回自身。因为是递归，往上回溯是已经计算完了，所以一边为空就返回另一边，如果两侧都有，则当前root是共同祖先。    

## 236. Lowest Common Ancestor of a Binary Tree 01 迭代

-----------------------------------------------------------------------------------

c++ std中set与unordered_set区别和map与unordered_map区别类似：

set基于红黑树实现，红黑树具有自动排序的功能，因此map内部所有的数据，在任何时候，都是有序的。
unordered_set基于哈希表，数据插入和查找的时间复杂度很低，几乎是常数时间，而代价是消耗比较多的内存，无自动排序功能。底层实现上，使用一个下标范围比较大的数组来存储元素，形成很多的桶，利用hash函数对key进行映射到不同区域进行保存。

set使用时设置：

我们需要有序数据（不同的元素）。
我们必须打印/访问数据（按排序顺序）。
我们需要元素的前身/后继者。

在以下情况下使用unordered_set：

我们需要保留一组不同的元素，不需要排序。
我们需要单个元素访问，即没有遍历。

-----------------------------------------------------------------------------------

我们用一个unordered_map存储父子映射，我们这里相当于BFS去找到p,q的映射位置。我们这里还有一个unordered_set来存储祖先节点，我们不断取p的节点，直到取到root为止，然后存入祖先，然后我们不断取q的祖先看是否再这里集合中，相当于找到其相交点则是我们所要求的祖先节点。


## 297. Serialize and Deserialize Binary Tree 01 

review cpp string

这道题的序列化：如果为空直接返回"[]",我们这里利用层序遍历，然后用一个islevel表示此是否为层，避免全NULL的那一层加入str.

反序列化我是利用双栈，我们先将str中的元素匹配出来生成节点存入que中，我们利用parent取连接que头两个元素，然后非NULL的元素存入parent中。

## 100. Same Tree 01 resursion

If two nodes have the same value, recurse in the same direction at the same time

TC : O(N)

SC : O(N)

## 100. Same Tree 02 resursion

The same as above

## 100. Same Tree 03 BFS two queue

level tranvrse to compare one by one.

TC : O(min(m , n))

SC : worst O(2 ^ H) but the solution says O(min(m,n)). I think it's not right

## 100. Same Tree 03 BFS one queue

## 124. Binary Tree Maximum Path Sum 01 框架

这里利用了递归的框架

后续遍历

每次记录一个倒V字，并取最大的更新

返回的是一边加上node，因为是path。

这个是都要遍历一次

时间复杂度O(N)

空间复杂度O(N)

## 99. Recover Binary Search Tree 01 

先来个笨办法

先中序遍历成一个一维数组，然后吧值排序一下，然后依次赋值

时间复杂度 O(n) 

空间复杂度 O(n)

虽然笨，但可针对任意数目错乱情况

## 99. Recover Binary Search Tree 02

这次用了双指针法，因为他是两个节点swap了一下，我们first代表第一个节点，second代表第二个节点

中序遍历，判断前一个结点是否大于当前的，先第一次定下第一个节点就不变了，然后两两比较，然后不断变更second到最后一个错误结点。

然后最后交换值

Time O(n)

space O(n)

## 99. Recover Binary Search Tree 03 

02的迭代法，中序遍历就是利用一个栈，先把left一路到底存储

然后中间逻辑进行比较和遍历法一样，然后指向right去右边挂载的子树进行遍历。

注意框架，不断的取栈(left),还有右侧挂载子树

time O(N)

space O(n)

## 99. Recover Binary Search Tree 04

TODO 

这道题的真正符合要求的解法应该用的 Morris 遍历，这是一种非递归且不使用栈，空间复杂度为 O(1) 的遍历方法

https://www.cnblogs.com/grandyang/p/4298069.html

https://www.cnblogs.com/grandyang/p/4297300.html

http://web.archive.org/web/20150308080843/http://noalgo.info/832.html

https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html

## 98. Validate Binary Search Tree 01 递归

这里先存了个preval，用于前后比较，我们这里设置成INT_MIN

这里的cnt的作用是，我们允许第一个节点也是INT_MIN

TIME O(N)

SPACE O(N)

## 98. Validate Binary Search Tree 02 迭代

迭代框架用栈

TIME O(N)

SPACE O(N)

## 98. Validate Binary Search Tree 03 Morris

其实morris这里比较这么思考，morris框架上，两个地方print，所有的逻辑都在这里进行

我们在这里每次比较和记录当前位置，也就是下一次的上一次。

TIME O(N)

SPACE O(1)

TODO: 为什么去掉break跑满才能过