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
                printf("Converted String: ");
                for(i = 0; str[i] != '\0'; i++)
                {
                    if(str[i] >= 'A' && str[i] <= 'Z')
                        printf("%c", str[i] + 32);
                    else
                        printf("%c", str[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 3);

    return 0;
}
