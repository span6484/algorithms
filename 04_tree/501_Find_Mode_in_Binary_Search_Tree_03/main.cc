class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* prev;
        int mx = 0;
        unordered_map<int, int> mp;
        while(root) {
            if(!root->left) {
                mx = max(mx, ++mp[root->val]);
                root = root->right;
            } else {
                prev = root->left;
                while(prev->right && prev->right != root) {
                    prev = prev->right;
                }
                if(!prev->right) {
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;
                    mx = max(mx, ++mp[root->val]);
                    root = root->right;
                }
            }
        }
        for(const auto& m : mp) {
            if(mx == m.second)
                res.push_back(m.first);
        }
        return res;

    }
};