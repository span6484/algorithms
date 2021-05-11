class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        while(l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *prev = nullptr;
        while(!st1.empty() or !st2.empty() or carry) {
            int a = st1.empty() ? 0 : st1.top();
            int b = st2.empty() ? 0 : st2.top();
            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();
            int num = a+b+carry;
            carry = num / 10;
            num = num % 10;
            auto cur = new ListNode(num);
            cur->next = prev;
            prev = cur;
        }
        return prev;
    }
};