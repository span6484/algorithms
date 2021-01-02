class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(++cnt == k) {
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
private:
    int cnt = 0;
};