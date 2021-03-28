#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Linked_List_Node{
    char data;
    struct Linked_List_Node * next;    
} Node;

int len(Node * head) {
    int count = 0;
    while( head != NULL ) {
        count++;
        head = head->next;
    }
    return count;
}

void add_to_middle(Node * head, char data) 
{
    int count = len(head);

    Node * node = head;
    for(int i=1; i<count/2; i++) {  //都行
        node = node->next;
    }

    Node * new_node = (Node *)calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = node->next;
    node->next = new_node;
}

int main(){

    Node * head = (Node *)calloc(1, sizeof(Node));
    head->data = 'A';
    head->next = (Node *)calloc(1, sizeof(Node));
    head->next->data = 'B';
    head->next->next = (Node *)calloc(1, sizeof(Node));
    //head->next->next->data = 'C';
    //head->next->next->next = NULL;

    add_to_middle(head, 'Z');
    while( head != NULL ) { printf( "%c", head->data); head=head->next;}

    return 0;
}