#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d", a[i]);
    }
}
int main()
{
    int a[] = {20, 30, 40, 50, 60, 70};
    int n = 6;
    printarray(a, n);

    return 0;
}