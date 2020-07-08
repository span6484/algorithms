class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(mp[node->val]) return mp[node->val];
        Node* root = new Node(node->val);
        mp[root->val] = root;
        vector<Node*> nb = node->neighbors;
        for(int i = 0; i < nb.size(); i++) {
            root->neighbors.push_back(cloneGraph(nb[i]));
        }
        return root;
    }
    
private:
    unordered_map<int, Node*> mp;
};