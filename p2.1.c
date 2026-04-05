  GNU nano 7.2                                                                c4.c
#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
    {
        printf("a is max = %d", a);
    }
    else if (b >= a && b >= c)
    {
        printf("b is max = %d", b);
    }
    else
    {
        printf("c is max = %d", c);
    }

    return 0;
}













                                                                     [ Read 24 lines ]
^G Help          ^O Write Out     ^W Where Is      ^K Cut           ^T Execute       ^C Location      M-U Undo         M-A Set Mark     M-] To Bracket
^X Exit          ^R Read File     ^\ Replace       ^U Paste         ^J Justify       ^/ Go To Line    M-E Redo         M-6 Copy         ^Q Where Was
