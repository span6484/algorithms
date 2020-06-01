#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(!head || !head->next) return NULL;
    struct ListNode* back = head;
    struct ListNode* forw = head;
    int i = 0;
    for(i = 0; i < n; i++){
        forw = forw->next;
    }
    if(!forw){
        head = head->next;
    }else{
        forw = forw->next;
        while(forw){
            forw = forw->next;
            back = back->next;
        }
        back->next = back->next->next;
    }
    return head;

}

int main() {
    printf("Hello, World!\n");
    return 0;
}