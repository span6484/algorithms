struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head) return head;
    int cnt = 0;
    struct ListNode* cur = head;
    struct ListNode* tmp = NULL;
    while(cur != NULL) {
        cnt++;
        tmp = cur;
        cur = cur->next;
    }
    int steps = cnt - k % cnt;
    cur = head;
    while(steps > 1){
        cur = cur->next;
        steps--;
    }
    tmp->next = head;
    tmp = cur->next;
    cur->next = NULL;
    return tmp;
}

