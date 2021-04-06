class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        deque<TreeNode*> dq;
        bool flag = false;
        dq.push_back(root);
        TreeNode* cur;
        while(!dq.empty()) {
            vector<int> ele;
            int sz = dq.size();
            for(int i = 0; i < sz; i++) {
                if(flag) {
                    cur = dq.front(); dq.pop_front();
                } else {
                    cur = dq.back(); dq.pop_back();
                }
                ele.push_back(cur->val);
                if(flag) {
                    if(cur->right) dq.push_back(cur->right);     
                    if(cur->left) dq.push_back(cur->left);
                } else {
                    if(cur->left) dq.push_front(cur->left);
                    if(cur->right) dq.push_front(cur->right);     
                }
            }
            flag = !flag;
            res.push_back(ele);
        }
        return res;
    }
};