#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    printf("Hello world!\n");
}


/*

Q1 Matrix
   
[ 0  1   0  1  0 ]
  0  0   1  0  1
  0  0   0  1  1
  0  0   0  0  0
  1  0   0  0  0

Q1 List

[0] -> [1] -> [3]
[1] -> [2] -> [4]
[2] -> [3] -> [4]
[3] 
[4] -> [0]

Q2 Matrix:

   O(|V|^2) * [O(1) + O(1)]  = O(|V|^2)

Q2 List:
   O(|V|^2) * [O(|V|) + O(|V|)]  = O(|V|^3)

不管了， 以书本为准吧。


老师的视频说了这个书有错没？  
List remove an edge should be O(|E|) not O(|V|)

then
   O(|V|^2) * [O(|V|) + O(|E|)]  = O(|V|^3)

*/



