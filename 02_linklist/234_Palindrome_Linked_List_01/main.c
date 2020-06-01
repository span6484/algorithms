bool isPalindrome(struct ListNode* head){
    struct ListNode *slow = head, *fast = head;
    if(!head || !head->next) return true;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* start = slow->next, *prev = NULL, *tmp;
    while(start->next){
        tmp = start->next;
        start->next = prev;
        prev = start;
        start = tmp;
    }
    start->next = prev;
    while(start){
        if(start->val != head->val) return false;
        start = start->next;
        head = head->next;
    }
    return true;

}
