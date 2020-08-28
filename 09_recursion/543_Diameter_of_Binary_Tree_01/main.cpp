class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int len = 0;
        helper(root, len);
        return len;
    }
    
    int helper(TreeNode* root, int& len) {
        int l = root->left ? helper(root->left, len) + 1 : 0;
        int r = root->right ? helper(root->right, len) + 1 : 0;
        len = max(len, l + r);
        return max(l, r);
    }
};