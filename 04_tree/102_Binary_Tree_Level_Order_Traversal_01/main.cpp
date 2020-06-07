class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        preorder(root, 0, res);
        return res;
    }

    void preorder(TreeNode* root, int level, vector<vector<int>>& res) {
        if(!root) return;
        if(level >= res.size()) {
            res.push_back(vector<int> {});
        }
        res[level].push_back(root->val);
        preorder(root->left, level+1, res);
        preorder(root->right, level+1, res);

    }
};