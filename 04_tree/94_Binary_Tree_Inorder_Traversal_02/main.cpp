class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            } 
            root = st.top(); st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};