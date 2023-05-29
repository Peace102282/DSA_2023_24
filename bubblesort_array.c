#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int a[], int n)
{
    int j, k;
    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n - 1; k++)
        {
            if (a[k] > a[k + 1])
            {
                swap(&a[k], &a[k + 1]);
            }
        }
    }
}

int main()
{
    int a[100], n, i;
    printf("enter the size of array");
    scanf("%d", &n);
    printf("enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("unsoerted list:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    bubble_sort(a, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}