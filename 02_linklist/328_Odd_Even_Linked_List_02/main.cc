class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *odd = head, *oddTail = head, *evenHead = head->next, *even = head->next;
        while(odd && even) {
            if(odd->next) {
                odd->next = odd->next->next;
                if(odd->next) oddTail = odd->next;
                odd = odd->next;
            }
            if(even->next) {
                even->next = even->next->next;
                even = even->next;
            }
        } 
        oddTail->next = evenHead;
        return head;
    }
};