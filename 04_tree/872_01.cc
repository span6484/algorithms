class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int> leaf1, leaf2;
        getLeaf(root1, leaf1);
        getLeaf(root2, leaf2);
        if(leaf1.size() != leaf2.size()) return false;
        while(!leaf1.empty()) {
            int l1 = leaf1.front(); leaf1.pop();
            int l2 = leaf2.front(); leaf2.pop();
            if(l1 != l2) return false;
        }
        return true;

    }
private:
    void getLeaf(TreeNode* root, queue<int>& leaf) {
        if(!root) return;
        if(!root->left && !root->right) leaf.push(root->val);
        getLeaf(root->left, leaf);
        getLeaf(root->right, leaf);
    }


};