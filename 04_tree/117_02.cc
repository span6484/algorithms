class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()) {
            int n = que.size();
            Node* prev = nullptr;
            for(int i = 0; i < n; i++) {
                
                Node* cur = que.front(); que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
                if(i == 0) {
                    prev = cur;
                } else {
                    prev->next = cur;
                    prev = cur;
                }
            }
        }
        return root;
    }
};