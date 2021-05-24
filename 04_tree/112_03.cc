class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return helper(0, root, targetSum);
    }

    bool helper(int out, TreeNode* root, int targetSum) {
        if(!root) return false;
        out += root->val;
        if(out == targetSum && !root->left && !root->right) return true;
        return helper(out, root->left, targetSum) || helper(out, root->right, targetSum);
    }
};