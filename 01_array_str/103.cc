class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        deque<TreeNode*> dque;
        dque.push_front(root);
        bool flag = true;
        while(!dque.empty()) {
            vector<int> tmp;
            int n = dque.size();
            for(int i = 0; i < n; i++) {
                if(flag) {
                    TreeNode* node = dque.back(); dque.pop_back();
                    tmp.push_back(node->val);
                    if(node->left) dque.push_front(node->left);
                    if(node->right) dque.push_front(node->right);  
                } else {
                    TreeNode* node = dque.front(); dque.pop_front();
                    tmp.push_back(node->val);   
                    if(node->right) dque.push_back(node->right);                    
                    if(node->left) dque.push_back(node->left);
                }
            }
            res.push_back(tmp);
            flag = !flag;
        }
        return res;

    }
};