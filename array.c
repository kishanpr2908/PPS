  GNU nano 7.2                                                               array.c
#include <stdio.h>

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int i, sum = 0, sume = 0;
    int x, y;
    int *p = a;


    p = a + 1;

    for(i = 0; i < 5; i++)
    {
        x = *p;
        sum = sum + x;
        p = p + 2;
    }


    p = a;

    for(i = 0; i < 5; i++)
    {
        y = *p;
        sume = sume + y;
        p = p + 2;
    }

    printf("Even Sum = %d\n", sum);
    printf("Odd Sum = %d\n", sume);

    return 0;




                                                                     [ Wrote 33 lines ]
^G Help          ^O Write Out     ^W Where Is      ^K Cut           ^T Execute       ^C Location      M-U Undo         M-A Set Mark     M-] To Bracket
^X Exit          ^R Read File     ^\ Replace       ^U Paste         ^J Justify       ^/ Go To Line    M-E Redo         M-6 Copy         ^Q Where Was
