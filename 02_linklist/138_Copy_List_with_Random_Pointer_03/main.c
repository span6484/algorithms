struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    node->random = NULL;
    return node;
}

struct Node* copyRandomList(struct Node* head) {
	if(head == NULL) return head;
    struct Node* start = head;
    struct Node* tmp = NULL, *node = NULL;
    while(head != NULL) {
        tmp = head->next;
        node = createNode(head->val);
        head->next = node;
        node->next = tmp;
        head = tmp;
    }
    head = start;
    while(head != NULL && head->next != NULL) {
        if(head->random != NULL)
            head->next->random = head->random->next;
        head = head->next->next;
    }

    head = start;
    while(head != NULL && head->next != NULL && head->next->next != NULL) {
        tmp = head->next->next;
        head->next->next = tmp->next;
        head = tmp;
    }
    return start->next;
    
}