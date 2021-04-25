#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BlackListNode {
    char data;
    struct BlackListNode * next;
    struct BlackListNode * prev;
} Node;

Node * insert( Node * h, char c, int i ) {
    if( h == NULL) {
        Node * inserted = calloc( sizeof(Node), 1);
        inserted->data = c;
        inserted->prev=NULL;
        inserted->next=NULL;
        return inserted;
    }

    Node * curr = h;
    for(int k=0; k<i; k++) {
        if( curr->next == NULL || k==(i-1) ) {
            Node * inserted = calloc( sizeof(Node), 1);
            inserted->data = c;
            if( curr->next != NULL ) {
                curr->next->prev = inserted;
            }

            inserted->next = curr->next;
            inserted->prev = curr;

            curr->next = inserted;
            break;
        }
    }
    return h;
}


int main() {
    printf("%s!\n", "Hello CSCA48");
    return 0;
}