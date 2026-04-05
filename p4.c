#include <stdio.h>

int main()
{
    int arr[100], n;
    int pos, i, value;

    
    printf("Enter size of array: ");
    scanf("%d", &n);

    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    
    printf("\nArray elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    
    printf("\n\nEnter position to display element (1-based): ");
    scanf("%d", &pos);

    pos = pos - 1;   

    if(pos >= 0 && pos < n)
    {
        printf("Element at position %d is %d\n", pos + 1, arr[pos]);
    }
    else
    {
        printf("Invalid position!\n");
    }

    
    printf("\nEnter position to update (1-based): ");
    scanf("%d", &pos);

    pos = pos - 1;   

    if(pos >= 0 && pos < n)
    {
        printf("Enter new value: ");
        scanf("%d", &value);
        arr[pos] = value;
    }
    else
    {
        printf("Invalid position!\n");
    }

    
    printf("\nArray after update:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    
    printf("\n\nEnter position to delete (1-based): ");
    scanf("%d", &pos);

    pos = pos - 1;   

    if(pos >= 0 && pos < n)
    {
        for(i = pos; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;  
    }
    else
    {
        printf("Invalid position!\n");
    }

    
    printf("\nArray after deletion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}                                                                p5.c
