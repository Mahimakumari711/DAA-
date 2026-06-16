#include <stdio.h>

int main()
{
    int arr[20];
    int n, item, i, found = 0;

    printf("\nEnter size of array: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &item);

    /* Linear Search */
    for (i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            found = 1;
            printf("\nElement %d found at index %d", item, i);
            break;
        }
    }

    if (found == 0)
    {
        printf("\nElement %d not found in the array", item);
    }

    return 0;
}


Output :

Enter size of array: 5

Enter the elements of the array:
89 56 23 45 12

Enter the element to search: 23

Element 23 found at index 2
