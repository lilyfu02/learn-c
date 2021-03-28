#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_ROW_COUNT 6
#define DELIMITER ','

int main(){
    char table_to_sort[MAX_ROW_COUNT][MAX_STRING_LENGTH] = {
        "Will Song,USA",
        "Brian Harrington,Canada",
        "Angela Zavaleta,Peru",
        ""
    };
    
    sorted_by_alpha(table_to_sort);

    printf("---------------------------\n");
    for(int i = 0; i< MAX_ROW_COUNT;i++){
        printf("%s\n",table_to_sort[i]);
    }
}