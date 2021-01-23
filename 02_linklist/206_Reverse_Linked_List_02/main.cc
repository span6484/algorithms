class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base 
        if(!head || !head->next) return head;
        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
};
