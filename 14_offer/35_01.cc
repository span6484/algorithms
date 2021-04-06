class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *pre = nullptr, *cur = head;
        Node *newHead = nullptr;
        unordered_map<Node*, Node*> memo;
        while(cur) {
            Node* node = new Node(cur->val);
            memo[cur] = node;
            if(pre) pre->next = node;
            else newHead = node;
            pre = node;
            cur = cur->next;
        }
        cur = head;
        Node* node = newHead;
        while(cur) {
            node->random = memo[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return newHead;
    }
};