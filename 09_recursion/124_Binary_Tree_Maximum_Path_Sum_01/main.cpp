class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = root->val;
        helper(root, sum);
        return sum;
    }
    int helper(TreeNode* root, int& sum) {
        int l = root->left ? helper(root->left, sum) : 0;
        int r = root->right ? helper(root->right, sum) : 0;
        l = root->left && l + root->left->val >= 0 ? l + root->left->val : 0;
        r = root->right && r + root->right->val >=0 ? r + root->right->val :0;
        sum = max(sum, r + l + root->val);
        return max(l, r);
    }
};