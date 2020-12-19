class Solution {
public:
    int postOrder(TreeNode* root, int &res) {
        if(root == nullptr) return 0;
        int left = max(0, postOrder(root->left, res));
        int right = max(0, postOrder(root->right, res));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val; 
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        postOrder(root, res);
        return res;
    }
};