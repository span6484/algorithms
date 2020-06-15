# 树的遍历

## 144. Binary Tree Preorder Traversal 01 递归

树的递归方法很套路，套用即可

## 144. Binary Tree Preorder Traversal 01 迭代(stack)

这里就是每次将右节点放入再看左节点

## 94. Binary Tree Inorder Traversal 01

递归套路

## 94. Binary Tree Inorder Traversal 02

递归是先把左边装到底然后慢慢push进来存值，然后每次取栈顶元素存值然后看他右侧，这样就是左 - 中 - 右的顺序

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






