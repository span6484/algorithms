struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tmp = head;
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }
    while(l1 && l2) {
        if(l1->val <= l2->val) {
            tmp->next = l1;
            l1 = l1->next;
        }else {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    if(l1 == NULL) {
        tmp->next = l2;
    }
    if(l2 == NULL) {
        tmp->next = l1;
    }

    return head->next;    
}