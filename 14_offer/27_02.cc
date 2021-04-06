class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* left = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(left);
        return root;
    }
};