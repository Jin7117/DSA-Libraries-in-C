//Basic single linked list code with search,print,isempty,insertEnd, freememory functions.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* next;
} Node;


Node* tail;
Node* head;

Node* createNode(int data){
 Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode){
        printf ("Memory allocation failed\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void insertEnd(int data){
    Node* newNode = createNode(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail ->next = newNode;
        tail = newNode;
    }

}

void printList(){
    if (head == NULL){ 
        printf("List is empty\n"); 
        return; 
    }


    Node* temp = head;
    while(temp != NULL){
        printf("%d ->",temp ->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeMemory(){
    Node* temp;
     while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
    printf("Memory freed\n");
}

Node* search(int element){
    Node* temp = head;
    while(temp != NULL){
       if(element == temp->data){
        printf("Element found\n");
        return NULL;
       }
        temp = temp->next;
    }
    printf("Element not found\n");
}

void isEmpty(){
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        printf("Node Exists\n");
        printList();
    }
}


int main(){

    isEmpty();

    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);

    search(7);

    printList();

    isEmpty();

    freeMemory();



    return 0;
}