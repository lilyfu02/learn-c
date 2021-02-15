#include <stdio.h>
#include <math.h>

int check(int * origin, int *dst, int count) {
    int j=0;
    for(int i=0;i<count;i++) {
        if(origin[i]>=0) {
            dst[j++] = origin[i];
        }
    }
    return j;
}

int main(int argc, char **agrv){
    int f[4] = {7,-2,5,-8};
    int t[4];

    int c = check(f,t,4);
    for(int i=0; i<c;i++)

        printf( "x=%d %d\n", i, t[i] );
    return 0;
}

