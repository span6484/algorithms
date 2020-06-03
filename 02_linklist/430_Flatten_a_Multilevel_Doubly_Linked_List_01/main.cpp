class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) 
            return head;
        Node* res = head; 
        Node* tmp = NULL;
        while(head != NULL) {
            if(head->child != NULL) {
                tmp = head->next;
                head->next = head->child;
                head->child->prev = head;
                head->child = NULL;
                while(head->next != NULL) {
                    head = head->next;
                    if(head->child != NULL)
                        head = flatten(head);
                }
                head->next = tmp;
                if(tmp != NULL) {
                    tmp->prev = head; 
                }   
            }
            head = head->next;
        }
        return res;
    }
};