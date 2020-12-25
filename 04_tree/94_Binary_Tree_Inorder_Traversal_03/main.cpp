class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;

        while(root) {
            if(!root->left) {
                v.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* prev = root->left;
                while(prev->right != nullptr && prev->right != root) {
                    prev = prev->right;
                }
                if(!prev->right) {
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return v;

    }
};