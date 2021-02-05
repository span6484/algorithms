class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head->next;
        // 找中点
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        // 翻转
        ListNode *pre = nullptr, *next = nullptr;
        while(slow) {
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        // 比较
        while(pre) {
            if(pre->val != head->val) return false;
            pre = pre->next;
            head = head->next; 
        }
        return true;
    }
};