  GNU nano 7.2                                                                p6.c *

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int size = 0, newSize, choice, i;

    while (1) {
        printf("\nDynamic Array Operations:\n");
        printf("1 - Create a new dynamic array (malloc)\n");
        printf("2 - Add elements to the array\n");
        printf("3 - Resize the array (realloc)\n");
        printf("4 - Display the array\n");
        printf("5 - Free memory and exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (arr != NULL) {
                printf("Array already exists. Free it first before creating new one.\n");
                break;
            }

            printf("Enter the number of elements to allocate: ");
            scanf("%d", &size);

            if (size <= 0) {
                printf("Invalid size.\n");
                break;
            }

            arr = (int *)malloc(size * sizeof(int));

                                                                     [ Read 116 lines ]
^G Help          ^O Write Out     ^W Where Is      ^K Cut           ^T Execute       ^C Location      M-U Undo         M-A Set Mark     M-] To Bracket
^X Exit          ^R Read File     ^\ Replace       ^U Paste         ^J Justify       ^/ Go To Line    M-E Redo         M-6 Copy         ^Q Where Was
