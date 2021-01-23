class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* node = root;
        stack<TreeNode*> st;
        TreeNode* prev;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if(!root->right || root->right == prev) {
                st.pop();
                TreeNode* tmp = root->left;
                root->left = root->right;
                root->right = tmp;
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return node;
    }
};