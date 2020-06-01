#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

int countNode(struct ListNode* node){
    struct ListNode* cur = node;
    int cnt = 0;
    while(cur){
        cur = cur->next;
        cnt++;
    }
    return cnt;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(!head || !head->next) return NULL;
    int total = countNode(head);
    int idx = total - n - 1;
    int i = 0;
    struct ListNode* cur = head;
    if(total == n){
        head = head->next;
    }else{
        for(i = 0; i < idx; i++){
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    return head;


int main() {
    printf("Hello, World!\n");
    return 0;
}