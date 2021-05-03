class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        for(int i = 0; i < left-1; i++) {
            prev = prev->next;
            head = head->next;
        }
        ListNode* l = prev;
        ListNode* r = head;
        ListNode* next = head->next;
        for(int i = left-1; i < right-1; i++) {
            head->next = prev;
            prev = head;
            head = next;
            next = head->next;
        }
        head->next = prev;
        l->next = head;
        r->next = next;
        return dummy->next;

    }
};