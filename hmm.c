#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sum(int a, int b)
{
    int sum = 1, i;
    for (i = 0; i < b; i++)
    {
        sum = sum * a;
    }
    printf("%d\n", sum);
}
int main()
{
    int a, b;
    clock_t start, stop;
    scanf("%d%d", &a, &b);
    start = clock();
    sum(a, b);
    stop = clock();
    float time_r = (float)(stop - start) / CLOCKS_PER_SEC;
    printf("\ntime taken: %f\n", time_r);
}