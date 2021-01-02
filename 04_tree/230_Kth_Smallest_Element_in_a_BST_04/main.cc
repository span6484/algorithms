class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int cnt = count(root->left);
        if(k <= cnt) {
            return kthSmallest(root->left, k);
        } else if(k > cnt + 1){
            return kthSmallest(root->right, k - cnt - 1);
        }
        return root->val;
    }
    int count(TreeNode* root) {
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};