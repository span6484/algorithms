class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        helper(root, L, R, sum);
        return sum;
    }
    void helper(TreeNode* root, int L, int R, int& sum) {
        if(!root) return;
        if(root->val < L) helper(root->right, L, R, sum);
        else if(root->val > R) helper(root->left, L, R, sum);
        else {
            sum += root->val;
            helper(root->left, L, R, sum);
            helper(root->right, L, R, sum);
        }
    }
};