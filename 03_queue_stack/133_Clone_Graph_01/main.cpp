class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(visited[node->val]) return visited[node->val];
        Node* root = new Node(node->val);
        visited[node->val] = root;
        for(int i = 0; i < node->neighbors.size(); i++) {
            root->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return root;
    }
private:
    Node* visited[101];
};