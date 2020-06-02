
struct ListNode* create_node(int val) {
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tmp = res;
    
    int flag = 0;
    while(l1 != NULL && l2 != NULL) { 
        if(l1->val + l2->val + flag > 9){
            tmp->next = create_node(l1->val + l2->val + flag - 10);
            flag = 1;
        }else {
            tmp->next = create_node(l1->val + l2->val + flag);
            flag = 0;
        }
        tmp = tmp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL) {
        if(l1->val + flag > 9) {
            tmp->next = create_node(0);
            flag = 1;
        }else {
            tmp->next = create_node(l1->val + flag);
            flag = 0;
        }
        l1 = l1->next;
        tmp = tmp->next;
    }
    while(l2 != NULL) {
        if(l2->val + flag > 9) {
            tmp->next = create_node(0);
            flag = 1;
        }else {
            tmp->next = create_node(l2->val + flag);
            flag = 0;
        }
        l2 = l2->next;
        tmp = tmp->next;
    }
    if(flag){
        tmp->next = create_node(1);
    }
    return res->next;
}
