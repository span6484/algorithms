#include <stdio.h>
typedef struct{
    int val;
    struct Node* next;
}Node;


typedef struct {
    Node* head;
} MyLinkedList;

/** Initialize your data structure here. */
//创造一个空链表
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)calloc(1,sizeof(MyLinkedList));
    return list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0) {return -1;}
    Node* cur = obj->head;
    int i =0;
    while(cur){
        if(i == index){
            return cur->val;
        }
        i++;
        cur = cur->next;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* head = (Node*)calloc(1,sizeof(Node));
    head->val = val;
    head->next = obj->head;
    obj->head = head;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* tail = (Node*)calloc(1,sizeof(Node));
    tail->next = NULL;
    tail->val = val;
    Node* cur = obj->head;
    if(!cur){
        obj->head = cur;
        return;
    }
    while(cur->next){
        cur = cur->next;
    }
    cur->next = tail;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    Node* cur = obj->head;
    Node* ins = (Node*)calloc(1,sizeof(Node));
    ins->val = val;
    ins->next = NULL;
    int i = 0;
    while(cur){
        if(index == 0) {
            ins->next = obj->head;
            obj->head = ins;
            return;
        }else if(i == index-1){
            ins->next = cur->next;
            cur->next = ins;
            return;
        }
        cur = cur->next;
        i++;
    }
    obj->head = ins;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    Node* cur = obj->head;
    int i = 0;
    while(cur){
        if(index == 0){
            obj->head = obj->head->next;
            return;
        }
        else if(i == index-1 && cur->next){ //这里因为index-1>=0，所以这里要讨论一下
            Node* tmp = cur->next;
            cur->next = tmp->next;
            return;
        }
        i++;
        cur = cur->next;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* cur = obj->head;
    while(cur){
        Node* tmp = cur;
        cur = cur->next; 
        free(tmp);
        tmp = NULL;
    }
}


// 遍历辅助函数
void mytraverse(MyLinkedList* obj){
    Node* cur = obj->head;
    while(cur){
        printf("%d\n",cur->val);
        cur = cur->next;
    }

}


int main() {
//    //test list create
//    MyLinkedList* obj = myLinkedListCreate(); //create successful
//
//    //test link
//    Node* node1 = (Node*)calloc(1,sizeof(Node));
//    if(node1){
//        printf("Create node1 successfully!\n");
//        node1->next = NULL;
//        node1->val = 0;
//    }
//    if(!obj->head){
//        printf("head is NULL\n");
//        obj->head = node1;
//    }
//    printf("------------------------\n");
//
//    // test add tail
//    myLinkedListAddAtTail(obj,1);
//    myLinkedListAddAtTail(obj,2);
//    myLinkedListAddAtTail(obj,3);
//    //0,1,2,3
//    mytraverse(obj);
//    printf("------------------------\n");
//
//    // test add head
//    myLinkedListAddAtHead(obj,11);
//    myLinkedListAddAtHead(obj,12);
//    myLinkedListAddAtHead(obj,13);
//    //13,12,11,0,1,2,3
//    mytraverse(obj);
//    printf("------------------------\n");
//
//    //test listGet
//    int param0 = myLinkedListGet(obj,0); //13
//    printf("%d\n",param0);
//    int param2 = myLinkedListGet(obj,2); //11
//    printf("%d\n",param2);
//    int param5 = myLinkedListGet(obj,5); //2
//    printf("%d\n",param5);
//
//    printf("------------------------\n");
//    // test add at index
//    myLinkedListAddAtIndex(obj,1,100);
//    mytraverse(obj);
//    printf("------------------------\n");
//    //test del at idx
//    myLinkedListDeleteAtIndex(obj,1);
//    mytraverse(obj);
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtIndex(obj,0,10);
    mytraverse(obj);
    myLinkedListAddAtIndex(obj,0,20);
    myLinkedListAddAtIndex(obj,1,30);
    mytraverse(obj);
    int get = myLinkedListGet(obj,0);
    printf("%d",get);

    return 0;

}