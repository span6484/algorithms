// TODO : 加了break反而不行是为什么

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode* log = nullptr;
        bool flag = true;
        while(root) {
            if(!root->left) {
                if(log && log->val >= root->val) {
                    flag = false;
                    // break;
                }
                log = root;
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
                    if(log && log->val >= root->val) {
                        flag = false;
                        // break;
                    }
                    log = root;
                    root = root->right;
                }
            }
        }
        return flag;
    }
};