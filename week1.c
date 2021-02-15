#include <stdio.h>
#include <math.h>
#include <string.h>

int strlen(char * arr) {
    int len = 0;
    while( arr[len] != 0)
        len++;
    return len;
}

int strcpy(char * dst, char * src ) {
    int pos = 0;
    while( src[pos] != '\0' ) {
        dst[pos] = src[pos];
        pos ++;
    }
    dst[pos] = 0;
    return pos;
}

int strcat(char * dst, char * src) {
    int len = strlen(dst);
    int pos = 0;
    while( src[pos] != '\0' ) {
        dst[len + pos] = src[pos];
        pos ++;
    }
    dst[len + pos] = 0;
    return pos;
}

int main(){
    char love_story[100];
    strcpy(love_story,"They break up");
    strcat( love_story, " heart");
    char sentence[100] = {'H','E','L','L','O','\0'};
    for(int i = 0;i<strlen(sentence);i++){
        printf("%c\n",sentence[i]);
    }
    printf("%s\n",sentence);
    printf("%s\n",love_story);
    for(int i = 4;i<strlen(love_story);i++){
        printf("%c\n",love_story[i]);
    }
    int arr[10];
    printf("%d",arr[6]);



   
   }

