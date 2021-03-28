#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Linked_List_Node{
    char data;
    struct  Linked_List_Node* next;
} Node;

Node * delete_last(Node * head, char val){
    Node * curr = head;
    Node * prior = NULL;

    if(head == NULL )
    return NULL;
    //skip the first one , and try to find the last one
    while( curr != NULL ) {
        if( curr ->next->data == val ) {
            prior = curr;
        }
        curr = curr->next;
    }

    if( prior == NULL ) {
        //check the head
        if( head->data == val ) {
            Node * new_head = head->next;
            free( head );
            return new_head;
        }
        // not found
        return head; 
    }
    // found
    Node * to_del =  prior->next;
    prior->next = prior->next->next;
    free( to_del );
    return head;
}

/*
Stack  A C E \0
Queue  B D F ?

我感觉老师出错题目了， i<7 会越界。应该是 i<6才对。
如果是 i<7， 打印的是下面的：
\0  E  C  A
B   D  F  ?

如果是 i<6， 则是
E  C  A
B  D  F
*/
int main(){

    char buffer[7] = "ABCDEF";
    for(int i=0; i<7; i+=2) {
        printf( "%c  %c \n", buffer[i], buffer[i+1]);
    }

    printf( "Hello %s", "World!");
    
    return 0;
}