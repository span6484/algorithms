class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode *slow = head, *fast = head->next;
        while(slow != fast) {
            if(!fast || !fast->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        slow = slow->next;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};