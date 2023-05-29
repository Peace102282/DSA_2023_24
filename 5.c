#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100

struct stack
{
    int data[size];
    int top;
};

int main()
{
    FILE *file;
    int i, randomNumber;

    file = fopen("random_numbers.txt", "w");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    srand(time(NULL));

    int random_to_generate;
    printf("how many random numbers you want:");
    scanf("%d", &random_to_generate);
    for (i = 0; i < random_to_generate; i++)
    {
        randomNumber = rand() % 100;
        fprintf(file, "%d\n", randomNumber);
    }
    fclose(file);
    file = fopen("random_numbers.txt", "r");
    if (file == NULL)
    {
        printf("error to open file\n");
        return 1;
    }
    printf("random numbers are:\n");
    while (fscanf(file, "%d", &randomNumber) != EOF)
    {
        printf("%d\n", randomNumber);
    }

    fclose(file);

    FILE *fp1 = fopen("random_numbers.txt", "r");

    printf("random numbers generated and saved in 'random_numbers.txt'\n");
    int n, c;
    struct stack *sptr;
    struct stack s;
    sptr = &s;
    sptr->top = -1;
    while (1)
    {

        printf("enter a choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:

            push(sptr, fp1);
            break;
        case 2:
            pop(sptr);
            break;
        case 3:
            display(sptr);
            break;
        case 4:
            exit(0);

        default:
            printf("enter correct choice\n");
            break;
        }
    }

    return 0;
}
void push(struct stack *sptr, FILE *fp1)
{
    if (sptr->top == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int x;
        fscanf(fp1, "%d", &x);
        sptr->top++;
        sptr->data[sptr->top] = x;
    }
}
void pop(struct stack *sptr)
{
    int num;
    if (sptr->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        num = sptr->data[sptr->top];
        sptr->top--;
        printf("poped:%d\n", num);
    }
}
void display(struct stack *sptr)
{
    int i;
    if (sptr->top == -1)
    {
        printf("Stack empty\n");
    }
    else
    {

        for (i = sptr->top; i >= 0; i--)
        {
            printf("%d\n", sptr->data[i]);
        }
    }
}
