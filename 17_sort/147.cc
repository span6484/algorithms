class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* cur = head->next;
        head->next = nullptr;
        while(cur) {
            ListNode* tmp = dummy->next;
            ListNode* prev = dummy;
            while(tmp && tmp->val < cur->val) {
                tmp = tmp->next;
                prev = prev->next;
            }
            if(!tmp) {
                prev->next = cur;
                ListNode* node = cur;
                cur = cur->next;
                node->next = nullptr;
            } else {
                prev->next = cur;
                ListNode* node = cur;
                cur = cur->next;
                node->next = tmp;
            }
         }
         return dummy->next;
    }
};