/*
  Advanced Doubly Linked List Implementation
 
  Functions included:
   - createNode()
   - createList()
   - printList(listName)
   - isEmpty(listName)
   - insertAtTail(listName, data)
   - deleteTail(listName)
   - insertAtHead(listName, data)
   - deleteHead(listName)
   - insertByIndex(listName, data, index)
   - deleteByIndex(listName, index)
   - deleteByValue(listName, value)
   - freeList(listName)
   - getSize(listName)
   - search(listName, value)
   - count(listName, value)
   - replace(listName, element , replacement)
   - isPalindrome(listName)
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Dll{
    Node* head;
    Node* tail;
    size_t size;
} Dll;


Node* createNode(int data){
Node* newNode = (Node*)malloc(sizeof(Node));
if(!newNode){
    printf("Memory Allocation Failed");
    return NULL;
}
newNode -> data = data;
newNode -> next = NULL;
newNode -> prev = NULL;
return newNode;
}


Dll *createList(){
    Dll *list = (Dll*)malloc(sizeof(Dll));
    if(!list){
        printf("memory allocation for new list failed");
        return NULL;
    }
    list->head=NULL;
    list->tail=NULL;
    list->size=0;
    return list;
}

int isEmpty(Dll *list){
    return list->size==0;
}
int isPalindrome(Dll *list){
    if(list->size==0){
        printf("list is empty");
        return -1;
    }
    Node *left = list->head;
    Node *right = list->tail;
 while(left != right && right->next !=left){
    if(left->data != right->data){
        return 0;
    }
   left = left->next;
    right = right->prev;
 }
 return 1;


}
size_t getSize(Dll *list){
    return list->size;
}
int search(Dll *list, int value)
{

    Node *temp = list->head;
    size_t index = 0;

    while (temp != NULL)
    {
        if (value == temp->data)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
int count(Dll *list, int value){

    Node *temp = list->head;
    size_t count=0;

    while (temp != NULL)
    {
        if (value == temp->data)
        {
           count++;
        }
        temp = temp->next;
    }
return count;
}
void replace(Dll *list, int element , int replace){
      Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data==element)
        {
           temp->data = replace;
        }
        temp = temp->next;
    }
}

void insertAtTail(Dll *list, int data){
    Node* newNode = createNode(data);
    if(list->size==0){
        list->head=newNode;
        list->tail=newNode;
    }
    else{
        list->tail->next=newNode;
        newNode->prev= list->tail;
        list->tail=newNode;
    }
    list->size++;
}
void insertAtHead(Dll *list, int data){
    Node* newNode= createNode(data);
    if(list->size==0){
        list->head= newNode;
        list->tail= newNode;
    }
    else{
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}
void insertByIndex(Dll *list, int data, int index){
    if(index < 0 || index > list->size-1){
        printf("Invalid index\n");
        return;
    };
    Node* newNode= createNode(data);

    if(index==0){
        insertAtHead(list,data);
        return;
    }
    else if (index == list-> size)
    {
        insertAtTail(list, data);
        return;
    }
    Node* temp= list->head;
    for (size_t i = 0; i < index -1; i++){
        temp = temp->next;
    }
    newNode->next = temp ->next;
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next->prev=newNode;
    
}

void deleteHead(Dll *list)
{

    if (isEmpty(list))
    {
        printf("List is empty; No head exists\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    if (list->head == NULL)
    {
        list->tail = NULL;
    }
    free(temp);
    list->size--;
}
void deleteTail(Dll *list){
    if(isEmpty(list)){
        printf("List is empty, no Tail exists\n");
        return;
    }
    Node* temp = list->head;
       if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }
    while(temp->next->next!=NULL){
        temp= temp->next;
    }
     free(list->tail);
    list->tail = temp;
    temp->next = NULL;
    list->size--;
}
void deleteNodeByIndex(Dll *list, int index){
      if(isEmpty(list)){
        printf("List is empty, no Tail exists\n");
        return;
    }
      if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    
    if (index==0)
    {
        deleteHead(list);
        return;
    }
    else if (index==list->size-1)
    {
        deleteTail(list);
        return;
    }
    Node* current = list->head;
    for (int i =0 ; i <index-1 ; i++ )
    {
        current= current->next;
        
    }
    Node* temp = current -> next;
    current->next = temp->next;
    free(temp);
    list->size--;
    
}
void deleteNodeByValue(Dll *list, int value){
      if(isEmpty(list)){
        printf("List is empty, no Tail exists\n");
        return;
    }
    int index = search(list,value);
    if(index==-1){
        printf("Element doesnt exists");
        return;
    }
    deleteNodeByIndex(list,index);
}



void printList(Dll *list){
    Node* temp = list ->head;
    while(temp!=NULL){
        printf("%d <-> ", temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}


void freeList(Dll *list){
    Node* temp= list->head;
    while(temp!=NULL){
        list->head=list->head->next;
        free(temp);
        temp = list->head;
    }
    free(list);
}

int main(){

 Dll* list1 = createList();


 insertAtTail(list1,10);
 insertAtTail(list1,20);
 insertAtTail(list1,10);
 insertAtTail(list1,40);

 insertAtHead(list1,99);

 insertByIndex(list1, 67,2);

printf("%d\n" , count(list1,10));

 printList(list1);

 freeList(list1);







    return 0;
}