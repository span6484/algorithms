class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p || !st.empty()) {
            while(p) {
                st.push(p);
                p = p->left;
            }
            p = st.top(); st.pop();
            if(pre) {
                if(pre->val > p->val) {
                    if(!first) first = pre;
                    second = p;
                }
            }
            pre = p;
            p = p->right;
        }
        swap(first->val, second->val);
    }
private:
    TreeNode *first = nullptr, *second = nullptr, *pre = nullptr;

};