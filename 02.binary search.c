Aim:To write a program for an element in a sorted array using binary search technique


#include <stdio.h>

int main()
{
    int n, key, i;

    // Asking user how many elements are needed
    printf("Enter the number of elements required: ");
    scanf("%d", &n);

    // Declaring the array
    int array[n];

    // Taking input for array elements (must be sorted for binary search)
    printf("Enter the elements in sorted order:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Reading the key element to search
    printf("Enter the key to search for: ");
    scanf("%d", &key);

    int low = 0, high = n - 1;
    int mid, found = 0;

    // Binary search loop
    while(low <= high)
    {
        mid = (low + high) / 2;

        // Compare key+1 with middle element (same idea as your linear search)
        if(array[mid] == key + 1)
        {
            printf("Element found at position %d\n", mid);
            found = 1;
            break;
        }
        else if(key + 1 < array[mid])
        {
            // Search in left half
            high = mid - 1;
        }
        else
        {
            // Search in right half
            low = mid + 1;
        }
    }

    // If not found
    if(!found)
    {
        printf("Element not found\n");
    }

    return 0;
}



output:
enter the number of elements n:
5
enter the elements:
2
4
6
8
10
enter the key
8

mid-2, Key-8
mid-3, Key-8
found at position 4

result:
The program successfully implements the Binary Search technique
to locate a key element in a sorted array and displays whether the element is present or not.


