class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool flag = false;
        int sum = 0;
        ListNode* tmp = new ListNode(0);
        ListNode* node;
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        while(l1 && l2) {
            if(flag) sum = l1->val + l2->val + 1;   
            else sum = l1->val + l2->val;
            if(sum > 9) {
                node = new ListNode(sum - 10);
                flag = true;
            } else {
                node = new ListNode(sum);
                flag = false;
            }
            l1 = l1->next;
            l2 = l2->next;
            pre->next = node;
            pre = pre->next;
        }
        while(l1) {
            if(flag) sum = l1->val + 1;   
            else sum = l1->val;
            if(sum > 9) {
                node = new ListNode(sum - 10);
                flag = true;
            } else {
                node = new ListNode(sum);
                flag = false;
            }
            l1 = l1->next;
            pre->next = node;
            pre = pre->next;
        }
        while(l2) {
            if(flag) sum = l2->val + 1;   
            else sum = l2->val;
            if(sum > 9) {
                node = new ListNode(sum - 10);
                flag = true;
            } else {
                node = new ListNode(sum);
                flag = false;
            }
            l2 = l2->next;
            pre->next = node;
            pre = pre->next;
        }
        if(flag) {
            node = new ListNode(1);
            pre->next = node;
        }
        return dummy->next;
    }
};