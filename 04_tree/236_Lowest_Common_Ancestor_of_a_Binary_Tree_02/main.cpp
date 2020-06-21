class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* top = root;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> que;
        parent[root] = NULL;
        que.push(root);
        while(parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            if(root->left) {
                parent[root->left] = root;
                que.push(root->left);
            }
            if(root->right) {
                parent[root->right] = root;
                que.push(root->right);
            }
            que.pop();
            root = que.front();
        }
        unordered_set<TreeNode*> ans;
        while(p) {
            ans.insert(p);
            p = parent[p];
        }
        while(ans.find(q) == ans.end()) {
            q = parent[q];
        }
        return q;
    }
};