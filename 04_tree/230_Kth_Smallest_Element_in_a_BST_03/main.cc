class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *prev;
        while(root) {
            if(!root->left) {
                if(++cnt == k) 
                    res = root->val;
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
                    prev->right = nullptr;
                    if(++cnt == k) 
                        res = root->val;
                    root = root->right;
                }
            }
        }
        return res;
    }
private:
    int cnt = 0;
    int res;
};