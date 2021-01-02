class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        unordered_map<int, int> mp;
        int mx = 0;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            mx = max(mx, ++mp[root->val]);
            root = root->right;
        }
        for(auto&& m : mp) {
            if(mx == m.second) 
                res.push_back(m.first);
        }
        return res;
    }
};
