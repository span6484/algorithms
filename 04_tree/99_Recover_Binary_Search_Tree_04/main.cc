class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        TreeNode *prev = nullptr, *log = nullptr, *first = nullptr, *second = nullptr;
        while(root) {
            if(!root->left) {
                if(!first) {
                    if(log && log->val > root->val) {
                        first = log;
                        second = root;
                    }
                } else {
                    if(first->val > root->val) second = root;
                }

                log = root;
                root = root->right;
            } else {
                prev = root->left;
                while(prev->right && prev->right != root) {
                    prev = prev->right;
                }
                if(!prev->right) {
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right =  nullptr;
                    if(!first) {
                        if(log && log->val > root->val) {
                            first = log;
                            second = root;
                        }
                    } else {
                        if(first->val > root->val) second = root;
                    }
                    log = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);

    }
};