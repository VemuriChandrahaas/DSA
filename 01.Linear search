Aim:To write a program for an element in a sorted array using linear search technique


#include <stdio.h>

int main()
{
    int n, key, i;

    // Asking user how many elements the array should hold
    printf("Enter the number of elements required: ");
    scanf("%d", &n);

    // Declaring an array of size 'n'
    int array[n];

    // Getting the array elements from the user
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Reading the element to search
    printf("Enter the key to search for: ");
    scanf("%d", &key);

    // Linear search through the array
    for(i = 0; i < n; i++)
    {
        // NOTE: We are checking array element with (key + 1)
        // This means: if key = 5, we search for 6 in the array
        if(array[i] == key + 1)
        {
            printf("Element found at position %d\n", i);
            break;
        }
    }

    // If the loop completes without finding a match
    if(i == n)
    {
        printf("Element not found\n");
    }

    return 0;
}


output:
Enter the number of elements required: 5
Enter the elements:
2
4
6
8
10
Enter the key to search for: 6
Element found at position 2

Result: 
        The program successfully searches for a given key element in a sorted array 
using the linear search technique and displays whether the element is found or not.
