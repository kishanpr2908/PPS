  GNU nano 7.2                                                                p5.c



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
}


^G Help          ^O Write Out     ^W Where Is      ^K Cut           ^T Execute       ^C Location      M-U Undo         M-A Set Mark     M-] To Bracket
^X Exit          ^R Read File     ^\ Replace       ^U Paste         ^J Justify       ^/ Go To Line    M-E Redo         M-6 Copy         ^Q Where Was
