class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur && cur->next) {
            if(cur->next->val != val) {
                cur = cur->next;
            } else {
                cur->next = cur->next->next;
            }
        }
        return dummy->next;
    }
};