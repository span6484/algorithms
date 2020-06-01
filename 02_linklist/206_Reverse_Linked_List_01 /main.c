#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head){
    if(!head || !head->next) return head;
    struct ListNode* cur = head->next;
    struct ListNode* pre = head;
    struct ListNode* nxt = NULL;
    while(cur){
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    head->next = NULL;
    head = pre;
    return head;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}