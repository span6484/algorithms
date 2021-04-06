class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            vector<int> ele;
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                auto cur = que.front(); que.pop();
                ele.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            res.push_back(ele);
        }
        return res;
    }
};