class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *cur = head;
        Node *dummy = new Node(0);
        Node *copy = dummy; 
        while(cur) {
            Node *tmp = new Node(cur->val);
            copy->next = tmp;
            copy = copy->next;
            memo[cur] = tmp;
            cur = cur->next;
        }
        copy = dummy->next;
        cur = head;
        while(cur) {
            if(cur->random) {
                copy->random = memo[cur->random];
            }
            cur = cur->next;
            copy = copy->next;
        }
        return dummy->next;
    }
private:
    unordered_map<Node*, Node*> memo;
};