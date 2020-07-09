class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* root = new Node(node->val);
        Node* res = root;
        mp[node] = root;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            node = q.front();
            root = mp[node];
            q.pop();
            vector<Node*> nb = node->neighbors;
            for(int i = 0; i < nb.size(); i++) {
                if(!mp[nb[i]]) {
                    Node* nei = new Node(nb[i]->val);
                    mp[nb[i]] = nei;
                    q.push(nb[i]);
                }
                root->neighbors.push_back(mp[nb[i]]);
            }
        }
        return res;
    }

private:
    unordered_map<Node*, Node*> mp; 
};