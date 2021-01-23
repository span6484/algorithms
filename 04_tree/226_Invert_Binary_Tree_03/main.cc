class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* node = root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            node = st.top(); st.pop();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return root;
    }
};