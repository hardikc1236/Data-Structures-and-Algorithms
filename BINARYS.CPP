#include <stdio.h>
#include <conio.h>
void main()
{
    int a[100], n, i, j, temp;
    int key, low, high, mid, found = 0;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nSorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\nEnter the element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(a[mid] == key)
        {
            found = 1;
            break;
        }
        else if(a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if(found == 1)
        printf("\nElement found at position %d in sorted array.", mid + 1);
    else
        printf("\nElement not found.");
    getch();
}