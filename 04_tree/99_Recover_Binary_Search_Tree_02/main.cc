class Solution {
public:
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(!pre) pre = root;
        else {
            if(pre->val > root->val) {
                if(!first) first = pre;
                second = root;
            }
            pre = root;
        }
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
private:
    TreeNode *pre = nullptr, *first = nullptr, *second = nullptr;
};