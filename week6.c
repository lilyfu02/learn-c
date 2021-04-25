#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Train_Station{
    int number;
    char color[50];
    struct Train_Station *next;
}train;

train *add_new_train(train *head, int number, char *color){
    train *new_train = NULL;
    new_train = (train *)calloc(1,sizeof(train));

    new_train->number = -1;
    strcpy(new_train->color,"");
    new_train->next = NULL;

    
    return new_train;
}

train *find_train(train *head, int num){
    train *p = NULL;
    p = head;
    while(p != NULL){
        if(p->number == num){
            return p;
        }
        p = p->next;
    }
    return p;
}

int main(){
    //Adding the first trains
    train *node = NULL;
    node = add_new_train;

    node->number = 1003;
    strcpy(node, "blue");
    //2nd train
    node->next;

    free(node);
    return 0;
}



