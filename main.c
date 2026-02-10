#include<stdio.h>
#define MAX_STUDENTS 67
int main()
{
    unsigned int pps_marks[MAX_STUDENTS] = {0};
    pps_marks[0] = 8;
    pps_marks[1] = 7;
    pps_marks[MAX_STUDENTS-1] = 9;
    
    int i;
    for(i=0 ; i < MAX_STUDENTS ; i++)
    {
        pps_marks[i] = (i + 1) * 5;
        printf("pps_marks[%d]=%d\n", i,pps_marks[i]);
    }
    
    
    return 0;
    
}