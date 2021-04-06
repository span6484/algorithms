class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        stack<Node*> st;
        Node* pre = nullptr;
        Node* first = nullptr;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(!first) first = root;
            if(pre) {
                pre->right = root;
                root->left = pre;
            } 
            pre = root;
            root = root->right;
        }
        first->left = pre;
        pre->right = first;
        return first;
    }
};