class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        size = seq.size();
    }
    
    int next() {
        return seq[idx++];
    }
    
    bool hasNext() {
        if(idx < size )
            return true;
        else
            return false;
    }
private:
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        seq.push_back(root->val);
        inorder(root->right);
    }
private:
    vector<int> seq;
    int idx = 0;
    int size;
};