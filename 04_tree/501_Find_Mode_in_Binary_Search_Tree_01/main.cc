class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return res;
        inorder(root);
        for(auto&& m : mp) {
            if(m.second == mx) {
                res.push_back(m.first);
            }
        }
        return res;
    }
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        mx = max(mx, ++mp[root->val]);
        inorder(root->right);
    }
private:
    vector<int> res;
    unordered_map<int, int> mp;
    int mx;
};