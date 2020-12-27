class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode *prev;
        while(root) {
            if(!root->left) {
                res.push_back(root->val);
                root = root->right;
            } else {
                prev = root->left;
                while(prev->right && prev->right != root) {
                    prev = prev->right;
                }
                if(!prev->right) {
                    res.push_back(root->val);
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;
                    root = root->right;
                }
            }
        }
        return res;
    }
};