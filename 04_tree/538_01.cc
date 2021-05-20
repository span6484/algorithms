class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        reverseInoder(root);
        return root;
    }
    void reverseInoder(TreeNode* root) {
        if(!root) return;
        reverseInoder(root->right);
        int tmp = root->val;
        root->val += sum_;
        sum_ += tmp;
        reverseInoder(root->left);
    }
private:
    int sum_;
};