class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                auto cur = que.front(); que.pop();
                if(!cur) continue;
                TreeNode* left = cur->left;
                TreeNode* right = cur->right;
                cur->left = right;
                cur->right = left;
                que.push(right);
                que.push(left);
            }
        }
        return root;
    }
};