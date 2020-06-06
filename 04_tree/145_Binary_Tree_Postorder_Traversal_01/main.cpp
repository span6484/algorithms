class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        postorder(root, res);
        return res;
    }
    void postorder(TreeNode* root, vector<int>& res) {
        if(root->left) postorder(root->left, res);
        if(root->right) postorder(root->right, res);
        res.push_back(root->val);
    }
};