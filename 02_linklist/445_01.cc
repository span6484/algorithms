class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = nullptr;
        ListNode* cur = nullptr;
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
        int flag = 0;
        int c = 0;
        while(!st1.empty() && !st2.empty()) {
            int a = st1.top(); st1.pop();
            int b = st2.top(); st2.pop();
            if(a+b+flag > 9) {
                c = a+b+flag-10;
                flag = 1;
            } else {
                c= a+b+flag;
                flag = 0;
            }
            if(!prev) {
                prev = new ListNode(c);
            } else {
                cur = new ListNode(c);
                cur->next = prev;
                prev = cur;
            }
        }
        while(!st1.empty()) {
            int a = st1.top(); st1.pop();
            if(flag + a > 9) {
                a = a + flag - 10;
                flag = 1;
            } else {
                a = a + flag;
                flag = 0;
            }
            if(!prev) {
                prev = new ListNode(a);
            } else {
                cur = new ListNode(a);
                cur->next = prev;
                prev = cur;
            }
        }
        while(!st2.empty()) {
            int b = st2.top(); st2.pop();
            if(flag + b > 9) {
                b = b + flag - 10;
                flag = 1;
            } else {
                b = b + flag;
                flag = 0;
            }
            if(!prev) {
                prev = new ListNode(b);
            } else {
                cur = new ListNode(b);
                cur->next = prev;
                prev = cur;
            }
        }
        if(flag) {
            cur = new ListNode(flag);
            cur->next = prev;
            prev = cur;
        }
        return prev;
        

    }
};