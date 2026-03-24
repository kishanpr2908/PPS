  GNU nano 7.2                                                                p23.c
#include <stdio.h>

int main()
{
    char str[100];
    int choice, length = 0;
    int i;

    printf("Enter String: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    do
    {
        printf("\n--- MENU ---");
        printf("\n1. Reverse String");
        printf("\n2. Upper to Lower Case");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Reversed String: ");
                for(i = length - 1; i >= 0; i--)
                {
                    printf("%c", str[i]);
                }
                printf("\n");
                break;

            case 2:

^G Help          ^O Write Out     ^W Where Is      ^K Cut           ^T Execute       ^C Location      M-U Undo         M-A Set Mark     M-] To Bracket
^X Exit          ^R Read File     ^\ Replace       ^U Paste         ^J Justify       ^/ Go To Line    M-E Redo         M-6 Copy         ^Q Where Was
