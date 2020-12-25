class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(prev && prev->val >= root->val) {
                return false;
            }
            prev = root;
            root = root->right;
        }
        return true;
    }
private:
    TreeNode* prev = nullptr;
};