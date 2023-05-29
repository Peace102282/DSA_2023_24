#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printrandom(int lower, int upper, int count)
{
    int i, j, num, duplicate;
    int nums[count];

    srand(time(NULL));
    for (i = 0; i < count; i++)
    {
        do
        {
            duplicate = 0;
            num = (rand()) % (upper - lower + 1) + lower;
            for (j = 0; j < count; j++)
            {
                if (num == nums[j])
                {
                    duplicate = 1;
                    break;
                }
            }

        } while (duplicate);
        {
            nums[i] = num;
            printf("%d\n", num);
        }
    }
}
int main()
{
    int lower = 1, upper = 10, count = 5;
    vq
        srand(time(NULL));
    printrandom(lower, upper, count);
    return 0;
}