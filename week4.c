#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_STR_LEN 1024

typedef struct Rest_Score
{
    char rest_name[MAX_STR_LEN];
    char rest_address[MAX_STR_LEN];
    int score;
} Review;

void fill_out_review(Review *info){
    /* takes a pointer to the review and fills out
    the name, address and score of the restaurant.
    */
    strcpy( info -> rest_name , "Lamplighter\'s"  );
    strcpy(info -> rest_address, "33 Delhi Crescent");
    info -> score = 6;
    return;
}
int main(){
    Review info;
    fill_out_review(&info);
    printf( "%s\n", info.rest_name );
    printf("%s\n", info.rest_address);
    printf("Score: %d",info.score);
}