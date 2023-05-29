#include <stdio.h>

int main()
{
    int choice, key;
    int array[100], size = 0;
    do
    {
        printf("menu\n");
        printf("1.search\n");
        printf("2.delete\n");
        printf("3.display\n");
        printf("4.insert\n");
        printf("5.read\n");
        printf("0.exit");
        printf("enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the elemnts to search");
            scanf("%d", &key);
            break;
        case 2:
            printf("enter the to delete:");
            scanf("%d", &key);
            break;
        case 3:
            break;
        case 4:
            printf("enter your elemts here:");
            scanf("%d", &key);
            break;
        case 5:
            printf("enter the number of elemnets in the array:");
            scanf("%d", &key);
            break;
        case 0:
            printf("exiting the program\n");
            break;

        default:
            printf("you have not slected a valid choice");
            break;
        }
    } while (choice != 0);
    return 0;
}