#include <stdio.h>
#include <stdlib.h>

typedef enum BOOL {
    FALSE=0,
    TRUE=1
} BOOL;

typedef struct  node
{
    int info;
    struct node* next;
    /* data */
} node;

void errorExit() {
    printf("memory allocation failed. exiting \n");
    exit(1);
}

void createList(node** headptr) {
    *headptr = NULL;
}

node* createNode(int info) {
    node* newnode = malloc(sizeof(node));
    if (newnode != NULL) {
        newnode->info = info;
        newnode->next = NULL;
    } else {
        errorExit();
    }
    return newnode;
}

void addNode(node** headptr, int info) {
    node* newnode = createNode(info);
    // check if this an empty list (head is NULL)
    if (*headptr == NULL) {
        *headptr = newnode;
    } else {
        node* tmp = *headptr;
        node* prev = NULL;
        while (tmp != NULL) {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = newnode;
    }
}

BOOL searchNode(node* head, int info) {
    node *tmp = head;
    while (tmp != NULL) {
        if (tmp->info == info)
            return TRUE;
        tmp = tmp->next;
    }
    return FALSE;
}

BOOL isEmpty(node* head) {
    return (head == (void*)NULL);
}

void traverse(node* head) {
    node* tmp = head;
    while (tmp != NULL) {
        printf("%d ",tmp->info);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {

    node* adt[5];
    for (int i=0;i<5;i++) {
        createList(&adt[i]);
    }
    addNode(&adt[0],1);
    addNode(&adt[0],4);

    addNode(&adt[1],0);
    addNode(&adt[1],4);
    addNode(&adt[1],2);
    addNode(&adt[1],3);

    addNode(&adt[2],1);
    addNode(&adt[2],3);

    addNode(&adt[3],1);
    addNode(&adt[3],4);
    addNode(&adt[3],2);

    addNode(&adt[4],3);
    addNode(&adt[4],0);
    addNode(&adt[4],1);

    for (int i=0;i<5;i++) {
        traverse(adt[i]);
    }    
}
