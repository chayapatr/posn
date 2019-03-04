#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node{
    char data;
    node* next;
};

void print (node* p) {
    while (p != NULL) {
        printf("%p %c %p\n",p, p->data, p->next);
        p = p->next;
    }
}

void insertLastNode (char data,node* head) {
    node* tail = head;
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    while (tail->next != NULL) tail = tail->next;
    tail->next = new_node;
}

void insertFirstNode (char data, node* head) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void removeLastNode (node* head) {
    node* tail = head;
    while (tail->next->next != NULL) tail = tail->next;
    tail->next = NULL;
}

node* head = NULL;

int main () {
    head = (node*) malloc(sizeof(node));
    head->data = 'A';
    head->next = (node*) malloc(sizeof(node));
    head->next->data = 'B';
    head->next->next = (node*) malloc(sizeof(node));
    head->next->next->data = 'C';
    head->next->next->next = NULL;
    insertLastNode('D', head);
    print(head);
    removeLastNode(head);
    print(head);
    insertFirstNode('H');
    print(head);
}
