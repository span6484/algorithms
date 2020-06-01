struct ListNode* removeElements(struct ListNode* head, int val){
    if(!head) return NULL;
    struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur->next = head;
    while(cur->next){
        if(cur->next->val == val){
            cur->next = cur->next->next;
        }else{
            cur = cur->next;
        }
    }
    while(head && head->val == val){
        head = head->next;
    }
    return head;
}
