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


def Foo(stra):
    res = ""
    stra += "0"
    cur = stra[0]
    cnt = 0
    for i in range(len(stra)):
        if(stra[i] == cur):
            cnt += 1
        else:
            res += cur
            res += str(cnt)
            cur = stra[i]
            cnt = 1
    return res