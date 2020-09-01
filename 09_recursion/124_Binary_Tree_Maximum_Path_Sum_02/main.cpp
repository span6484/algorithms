class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        helper(root, sum);
        return sum;
    }
    
    int helper(TreeNode* root, int& sum) {
        if(!root) return 0;
        int l = max(helper(root->left, sum), 0);
        int r = max(helper(root->right, sum), 0);
        sum = max(sum, l + r + root->val);
        return max(l, r) + root->val;
    }
};