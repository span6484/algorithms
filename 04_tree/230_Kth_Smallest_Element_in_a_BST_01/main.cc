class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }

    void inorder(TreeNode* root, const int k) {
        if(!root) return;
        inorder(root->left, k);
        if(++cnt == k) {
            res = root->val;
            return;
        }
        inorder(root->right, k);
    }
private:
    int cnt = 0;
    int res;
};