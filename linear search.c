#include <stdio.h>

int main()
{
    int n, key, i;
    printf("Enter the number of elements required: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        
        if(array[i] == key + 1)
        {
            printf("Element found at position %d\n", i);
            break;
        }
    }

    if(i == n)
    {
        printf("Element not found\n");
    }

    return 0;
}
