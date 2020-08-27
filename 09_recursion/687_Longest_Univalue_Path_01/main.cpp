class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int len = 0;
        helper(root, len);
        return len;
    }
private:
    int helper(TreeNode* root, int& len) {
        int l = root->left ? helper(root->left, len) : 0;
        int r = root->right ? helper(root->right, len) : 0;
        l = (root->left && root->left->val == root->val) ? l + 1 : 0;
        r = (root->right && root->right->val == root->val) ? r + 1 : 0;
        len = max(len, r + l);
        return max(r, l);
    }
};