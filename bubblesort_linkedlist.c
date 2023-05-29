#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void swapnodes(struct node *node1, struct node *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}
void bubblesort(struct node *head)
{
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->next != lptr)
            {
                swapnodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

    } while (swapped);
}

void printlist(struct node *head)
{
    struct node *node = head;
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n, data;

    printf("enter the number of elements:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter element %d:", i + 1);
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            printf("enter elemnt %d:", i + 1);
            scanf("%d", &data);
            insertnode(head, data);
        }
        printf("orignal list:");
        printlist(head);
        bubblesort(head);
        printf("\nsorted list:");
        printlist(head);
    }
    return 0;
}