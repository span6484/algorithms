class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                root = q.front();
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            depth++;
        }
        return depth;
    }
};