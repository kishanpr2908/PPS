
#include <stdio.h>
long int factorial_recursive(int n) 
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial_recursive(n - 1);
    }
}
long int factorial_iterative(int n)
{
    long int fact = 1;
    int i;

    for (i = 1; i <= n; i++) 
    {
        fact = fact * i;
    }
    return fact;
}
int main() 
{
    int choice, num;

    do 
    {
        printf("\n===== Factorial Menu =====\n");
        printf("1. Factorial using Iterative Method\n");
        printf("2. Factorial using Recursive Method\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);

                if (num < 0)
                    printf("Factorial not defined for negative numbers.\n");
                else
                    printf("Factorial (Iterative) = %ld\n", factorial_iterative(num));
                break;

            case 2:
                printf("Enter a number: ");
                scanf("%d", &num);

                if (num < 0)
                    printf("Factorial not defined for negative numbers.\n");
                else
                    printf("Factorial (Recursive) = %ld\n", factorial_recursive(num));
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
