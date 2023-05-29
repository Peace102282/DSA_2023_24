#include <stdio.h>

void bubblesort(int array[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int array[] = {1, 34, 4, 5, 55, 7, 7};
    int size = sizeof(array) / sizeof(array[0]);
    int i;

    printf("array before sortting\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    bubblesort(array, size);
    printf("\nafter sorting:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}