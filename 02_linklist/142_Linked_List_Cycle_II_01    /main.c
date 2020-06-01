#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    //先判断一下NULL
    if(!head || !head->next){
        return NULL;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(slow != fast){
        if(!fast || !fast->next){
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    slow = slow->next;
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}