#include <stdio.h>
#include <stdbool.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    //一般都要先有这个判断
    if(head == NULL || head->next == NULL){
        return false;
    }
    //create快慢指针
    struct ListNode* fast = head->next;
    struct ListNode* slow = head;
    while(slow != fast){
        if(fast == NULL || fast->next == NULL){
            return false;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;

}

int main() {
    printf("Hello, World!\n");
    return 0;
}