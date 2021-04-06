class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* pre = nullptr;
        ListNode* nex = head->next;
        while(nex) {
            head->next = pre;
            pre = head;
            head = nex;
            nex = nex->next;
        }
        head->next = pre;
        return head;
    }
};