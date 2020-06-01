struct ListNode* oddEvenList(struct ListNode* head){
    if(!head || !head->next || !head->next->next) return head;
    struct ListNode* head2 = head->next;
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    int cnt = 0;
    printf("cnt = %d\n",cnt);
    while(odd->next && even->next){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
        printf("%d\n", ++cnt);
    }
    odd->next = head2;
    return head;
}
