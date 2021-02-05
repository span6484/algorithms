class Solution {
public:
    string search(TreeNode* root, vector<TreeNode*>& res) {
        if(!root) return "#";
        string left = search(root->left, res);
        string right = search(root->right, res);
        string all = left + "," + right + "," + to_string(root->val);
        if(memo[all] == 1) {
            res.push_back(root);
        } 
        memo[all] += 1;

        return all;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        search(root, res);
        return res;
    }
private:
    unordered_map<string, int> memo;
};
