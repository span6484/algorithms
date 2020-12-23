class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> vals;
        inorder(root, nodes, vals);
        sort(vals.begin(), vals.end());
        for(int i = 0; i < nodes.size(); i++) {
            nodes[i]->val = vals[i]; 
        }
    }

    void inorder(TreeNode* root, vector<TreeNode*>& nodes, vector<int>& vals) {
        if(root == nullptr) return;
        inorder(root->left, nodes, vals);
        nodes.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, nodes, vals);
    }
};