#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Course_Record 
{
    char code[7];
    int num_students;
    float average;
} Course;

typedef struct Department_Record {
    Course courses[4];
    int num_courses;
} Department;

void add( Department * d, char* name, int n, float ava) {
    strcpy(d->courses[d->num_courses].code,name);
    d->courses[d->num_courses].num_students = n;
    d->courses[d->num_courses].average = ava;
    d->num_courses++;
}


int main(){
    Department d;
    d.num_courses = 0;
    add( &d, "CSC08", 800, 70.0);
    add( &d, "CSCA20", 300, 75.0);
    add( &d, "CSCA48", 500, 65.0);

    printf( "This is %s %d, %f. \n", 
        d.courses[0].code,
        d.courses[0].num_students, 
        d.courses[0].average);
}


1000
Department (前面4个Course，后面一个int。是连续的)
1000                                      1015                                       1030        1045     1060
Course[0]                                 Course[1]                                                       int number_course
code[7]               int num_s  float ava code[7]              int num_s  float ava  第三个       第四个   
[C][S][C][A][0][8][\0][ 800      ][  70.0 ][C][S][C][A][2][0][\0 ][300    ][ 75   ]

