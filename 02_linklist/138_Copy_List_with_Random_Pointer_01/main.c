struct Node* create_node(int val) {
    struct Node* res = (struct Node*)malloc(sizeof(struct Node));
    res->val = val;
    res->next = NULL;
    res->random = NULL;
    return res;
}

int index_node(struct TreeNode* index, const struct Node* head) {
    int i = 0;
    struct Node* res = head;
    while(index != res) {
        res = res->next;
        i++;
    }
    return i;
}

struct Node* copyRandomList(struct Node* head) {
    if(head == NULL) 
        return head;
    struct Node* res = create_node(head->val);
    struct Node* cur = res;
    struct Node* head_ = head;    
    struct Node* tmp;
    int index = 0, i = 0;

    while(head->next != NULL) {
        tmp = create_node(head->next->val);
        cur->next = tmp;
        head = head->next;
        cur = cur->next;
    }
    head = head_;
    cur = res;
    tmp = res;
    while(head != NULL){
        if(head->random != NULL) {
            index = index_node(head->random, head_);
            for(i = 0; i < index; i++) {
                tmp = tmp->next;
            }
            cur->random = tmp;
        }
        head = head->next;
        cur = cur->next;
        tmp = res;
    }
    return res;
}