#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node {
    char* data;            
    struct Node* prev;     
    struct Node* next;         
} Node;


Node* createNode(const char* data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        fprintf(stderr, "mijão enorme");
        exit(1);
    }

    newNode->data = strdup(data);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* createCharList() {
    Node* head = createNode(NULL);
    return head;
}

Node* insertEnd(Node* head, const char* data) {
    Node* newNode = createNode(data);
    
    if(head == NULL) {
        return newNode;
    }

        Node* curr = head;
        while (curr->next != NULL) {
            curr=curr->next;
        }
        curr->next=newNode;
        newNode->prev=curr;
        return head;
    
}

Node* find(Node* head, const char* data) {
    Node* curr = head;

    while (curr != NULL) {
            if (strcmp(curr->data, data) == 0) {
                return curr;
            }
            curr = curr->next;
    }
    return NULL; 
}

void delete(Node* head, const char* data) {
    Node* nodeToDelete = find(head, data);

    if(nodeToDelete == NULL) {
        printf("Node with data %s not found.\n", data);
        return;
    }

    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    } else {
        head = nodeToDelete->next;
    }

    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    free(nodeToDelete->data);
    free(nodeToDelete);
}

void freeList(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp->data);
        free(temp);
        }
    }

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%s ->", curr->data);
        curr = curr->next;
    }
}

 int main() {
    Node* head = NULL;

    head = insertEnd(head, "hello");
    head = insertEnd(head, "World,");
    head = insertEnd(head, "this");
    head = insertEnd(head, "is");
    head = insertEnd(head, "a");
    head = insertEnd(head, "doubly");
    head = insertEnd(head, "linked");
    head = insertEnd(head, "list");

    printf("This is the list:\n");
    printList(head);


    freeList(head);
    return 0;
 };