#include <stdio.h>

int main()
{

    void recursion(int n)
    {

        if (n < 0)
        {

            for (i = 1; i < n; i * 2)
            {
                printf("%d", n);
            }
            recursion(n - 1);
        }
    }
    return 0;
}
