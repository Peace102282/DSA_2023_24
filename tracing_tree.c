#include <stdio.h>
int main()
{
    void recursion(int n)
    {
        int n;
        if (n < 0)
        {
            printf("%d", n);
            recursion(n - 1);
        }
    }
    return 0;
}
