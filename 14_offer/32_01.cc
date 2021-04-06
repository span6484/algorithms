class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            auto cur = que.front(); que.pop();
            res.push_back(cur->val);
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        return res;

    }
};