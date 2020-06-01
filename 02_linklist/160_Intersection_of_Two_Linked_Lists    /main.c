#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int traverse_count(struct ListNode* node){
    int cnt = 0;
    struct ListNode* cur = node;
    while(cur){
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lengthA = traverse_count(headA);
    int lengthB = traverse_count(headB);
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    int diff = 0,i=0,length=0;
    if(lengthA > lengthB){
        diff = lengthA -lengthB;
        length = lengthB;
        for(i=0; i< diff; i++){
            curA = curA->next;
        }
    }else{
        diff = lengthB - lengthA;
        length = lengthA;
        for(i=0;i<diff;i++){
            curB = curB->next;
        }
    }
    for(i=0; i<length; i++){
        if(curA == curB){
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}
int main() {
    printf("Hello, World!\n");
    return 0;
}