#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB) return NULL;
    struct ListNode* pA = headA;
    struct ListNode* pB = headB;
    while(pA != pB){
        pA = pA == NULL? headB:pA->next;
        pB = pB == NULL? headA:pB->next;
    }
    return pA;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}