class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* tmp = st.top(); st.pop();
        pushall(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
private:
    stack<TreeNode*> st;
    void pushall(TreeNode* root) {
        for(; root != nullptr; st.push(root), root = root->left);
    }
};
