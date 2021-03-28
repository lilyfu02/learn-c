#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i=0;
    int count=0;

    char s[] = "Helloooooooo";

    while( s[i] != '\0') {
        for( int j=0; j<i; j++) {
                count++;
                printf( "%d %d\n", i, j);
        }
        i++;
    }

    printf("%d", count );
    return 0;
}

/*
int linked_list_search(LinkedList * l, char c ) {
    while( l != NULL ) {
        if( l->val == c )
            return 1;
        
        l = l->next;
    }
    return 0;
}

int mystery(LinkedList * l, char *s) {
    int i=0;
    int count=0;
    while( s[i] != '\0') {   --> m
        for( int j=0; j<i; j++) {
            if( linked_list_search( l, s[i])) {  (m-1)!
                count++;
            }

        }
        i++;
    }
    return count;
}
*/

/*
question 1:   
   m + (m-1)! +  (m-1)!*n*2 

question 2:
     Big O : (m-1)! * n 

*/


