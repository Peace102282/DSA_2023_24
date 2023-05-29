#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n);
void swap(int *a, int *b);

int main()
{
    int lower = 1, upper = 100, count = 10;
    srand(time(NULL));
    printrandom(lower, upper, count);
    printf("Random numbers generated and stored in 'random_numbers.txt'.\n");
    FILE *fp;
    int i, n, *arr;

    // Open file for reading
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read number of elements from file
    fscanf(fp, "%d", &n);

    // Allocate memory for array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Error allocating memory.\n");
        exit(1);
    }

    // Read array elements from file
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    // Close input file
    fclose(fp);

    // Sort array using bubble sort algorithm
    bubble_sort(arr, n);

    // Open file for writing
    fp = fopen("output.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write sorted array elements to file
    fprintf(fp, "%d\n", n);
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }

    // Close output file
    fclose(fp);

    // Free memory allocated for array
    free(arr);

    return 0;
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printrandom(int lower, int upper, int count)
{
    int i, num;
    FILE *fp;

    fp = fopen("random_numbers.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (i = 0; i < count; i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
}

