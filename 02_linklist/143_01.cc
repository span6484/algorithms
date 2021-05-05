class Solution {
public:
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> memo;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        int idx = 0;
        while(head) {
            memo[idx++] = head;
            head = head->next;
        }
        head = dummy;
        for(int i = 0; i < idx/2; i++) {
            head->next = memo[i];
            head->next->next = memo[idx-i-1];
            head = head->next->next;
        }
        if(idx % 2 == 1) {
            head->next = memo[idx/2];
            head = head->next;
        }
        head->next = nullptr;

        head = dummy->next;

    }

};