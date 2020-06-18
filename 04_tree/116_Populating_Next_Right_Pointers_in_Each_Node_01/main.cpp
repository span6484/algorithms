class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        Node* res = root;
        while(!q.empty()) {
            int len = q.size();
            Node *tmp = NULL;
            for(int i = 0; i < len; i++) {
                root = q.front();
                q.pop();
                if(root->right) q.push(root->right);
                if(root->left) q.push(root->left);
                root->next = tmp;
                tmp = root;
            }
        }
        return res;
    }
};
