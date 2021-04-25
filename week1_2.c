#include <stdio.h>
int main(){
    float N = 1.23456;
    int x = 2;
    float rounded = 0.0;
    for(int i = 0; i<=x;i++){
        rounded = round(N,x);
        printf("%f\n",rounded);
    }
}