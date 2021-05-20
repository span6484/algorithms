class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxi_ = 0;
        helper(root);
        return maxi_;
    }
private:
    int helper(TreeNode* root) {
        if(!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        maxi_ = max(maxi_, l+r);
        return max(l, r) + 1;
    }
private:
    int maxi_;

};