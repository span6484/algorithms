class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
    }

    ListNode* helper(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tmp = head->next;
        head->next = helper(head->next->next);
        tmp->next = head;
        return tmp;
    }
};