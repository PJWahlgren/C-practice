#include "stdlib.h"
#include "stdio.h"


typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList initList(){
    LinkedList list = {NULL,0};
    return list;
}

void addToList(LinkedList* list, int num){
    Node* newHead = malloc(sizeof(Node));
    newHead->value = num;
    newHead->next = list->head;
    list->head = newHead;
    list->size++;
}

void addToList2(int* ptr, int num) {
    Node* newHead = malloc(sizeof(Node));
    newHead->value = num;
    ptr = newHead;
    ptr++;
    ptr += 1;
}

void printList(LinkedList* list){
    printf("[%d]", list->size);
    Node* currNode = list->head;
    printf("[");
    while (currNode != NULL) {
        printf("%d", currNode->value);
        if (currNode->next != NULL) {
            printf(", ");
        }
        currNode = currNode->next;
    }
    printf("]\n");
}

void printNode(Node* node) {
    printf("{Value: %d, Next: %d}\n",node->value, node->next);
}

LinkedList tolist(int arr[], int length) {
    LinkedList list = initList();
    for (int i = 0; i < length; i++) {
        addToList(&list, arr[i]);
    }
    return list;
}

//Returns 1 if elem not found, 0 otherwise
int deleteElem(LinkedList* list, int elem) {
    Node* prevNode = list->head;
    if (prevNode == NULL) {
        return 1;
    }
    Node* currNode = prevNode->next;
    while (currNode != NULL) {
        if (currNode->value == elem) {
            prevNode->next = currNode->next;
            free(currNode);
            list->size--;
            return 0;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    return 1;
}

int main() {
    int arr[] = {1,2,3,4,5};
    LinkedList list = tolist(arr, 5);
    printList(&list);
    deleteElem(&list, 1);
    printList(&list);
    return 0;
}
