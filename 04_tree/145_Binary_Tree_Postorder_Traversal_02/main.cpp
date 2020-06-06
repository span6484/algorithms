class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st;
        deque<int> dq;
        TreeNode* tmp;
        st.push(root);
        while(!st.empty()) {
            tmp = st.top();
            st.pop();
            dq.push_front(tmp->val);
            if(tmp->left) st.push(tmp->left);
            if(tmp->right) st.push(tmp->right);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};