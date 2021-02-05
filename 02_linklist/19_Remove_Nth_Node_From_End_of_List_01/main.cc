class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if(!fast) return head->next;
        fast = fast->next;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};