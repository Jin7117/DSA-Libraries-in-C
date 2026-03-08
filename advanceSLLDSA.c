/*
  Advanced Singly Linked List Implementation
 
  Functions included:
 
   Creation:
     - createNode()
     - createList()
 
   Display & Status:
     - printList(listName)
     - isEmpty(listName)
     - get_size(listName)
 
   Insertion:
     - insertAtHead(listName, data)
     - insertAtTail(listName, data)
     - insertByIndex(listName, data, index)
 
   Deletion:
     - deleteHead(listName)
     - deleteTail(listName)
     - deleteByIndex(listName, index)
     - deleteByValue(listName, value)
 
   Utility:
     - search(listName, value)
     - freeList(listName)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Sll
{
    Node *head;
    Node *tail;
    size_t size;
} Sll;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation for newNode failed");\
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Sll *createList()
{
    Sll *list = (Sll *)malloc(sizeof(Sll));
    if (!list)
    {
        printf("Memory allocation for new list failed \n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int isEmpty(Sll *list)
{
    return list->size==0;
}

size_t get_size(Sll *list)
{
    return list->size;
}

void insertAtTail(Sll *list, int data)
{
    Node *newNode = createNode(data);
    if (list->size == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;

}
void insertAtHead(Sll *list, int data)
{
    Node *newNode = createNode(data);
    if (list->size == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;

}
void insertNodeByIndex(Sll *list, int data, int index){
    if(isEmpty(list)){
        printf("The list is empty\n");
        return;
    }
    if(index <0 || index >= list->size+1){
        printf("Invalid Index\n");
        return;
    }
    Node* newNode = createNode(data);
    if(index==0){
        insertAtHead(list,data);
        return;
    }
    else if (index==list->size)
    {
        insertAtTail(list,data);
        return;
    }

    Node* temp = list->head;
    for (size_t i = 0; i < index-1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp ->next = newNode;
    
}


int search(Sll *list, int value)
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


void deleteHead(Sll *list)
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
void deleteTail(Sll *list){
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
void deleteNodeByIndex(Sll *list, int index){
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
void deleteNodeByValue(Sll *list, int value){
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


void printList(Sll *list)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

void freeList(Sll *list)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        list->head = list->head->next;
        free(temp);
        temp = list->head;
    }
    free(list);
}

int main()
{

    Sll *list1 = createList();
    Sll *list2 = createList();

    insertAtTail(list1, 10);
    insertAtTail(list2, 10);

    insertAtTail(list1, 20);
    insertAtTail(list2, 20);

    insertNodeByIndex(list1,99,2);
    printList(list1);


    insertAtTail(list1, 30);
    insertAtTail(list2, 30);

    insertAtHead(list1, 80);
    insertAtHead(list2, 80);

    insertAtHead(list1, 90);
    insertAtHead(list2, 90);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    printf("Size of List 1: %zu\n", get_size(list1));
    printf("Search 20 in List 2: %d\n", search(list2, 20));

    deleteHead(list1);
    deleteTail(list2);
    deleteNodeByIndex(list2,2);
    deleteNodeByValue(list1,30);
    

    printList(list1);
    printList(list2);

    freeList(list1);
    freeList(list2);

    return 0;
}