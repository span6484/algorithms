## 模板汇总

## 分治

无


## 二叉树递归模板

```cpp
/* 二叉树遍历框架 */
void traverse(TreeNode root) {
    if(!root) return;
    // 前序遍历
    traverse(root->left)
    // 中序遍历
    traverse(root->right)
    // 后序遍历
}
```

## 总结二叉树迭代模板

- 前序遍历 

```cpp
void preorderTraversal(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        auto node = st.top(); st.pop();
        // do something here
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);
    }
}
```

- 中序遍历 

```cpp
void inorderTraversal(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> st;
    while(root || !st.empty()) {
        while(root) {
            st.push(root);
            root = root->left;
        } 
        root = st.top(); st.pop();      
        // do something here
        root = root->right;
    }
    return res;
}
```

- 后序遍历 

```cpp

// 我们什么时候才能访问节点。有如下两种情况：

// 当前经过节点是叶子节点。
// 当前经过节点的右子节点是上一次访问的节点。

void postorderTraversal(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> st;
    TreeNode* prev = nullptr;
    while(root || !st.empty()) {
        while(root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        if(!root->right || root->right == prev) {
            st.pop();
            // do something here
            prev = root;
            root = nullptr;
        } else {
            root = root->right;
        }
    }
}
```


https://github.com/youngyangyang04/leetcode-master