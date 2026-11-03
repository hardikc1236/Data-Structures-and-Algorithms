#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *createList(node *head);
node *Insert_beg(node *head, int x);
node *Delete_beg(node *head);
node *freeList(node *head);
void PrintList(node *head);
int readInt(int *value);
void main()
{
    int choice, x;
    node *head = NULL;
    do
    {
        clrscr();
        printf("***** SINGLY LINKED LIST *****\n\n");
        printf(" 1. Create a List\n");
        printf(" 2. Insert a node at the beginning\n");
        printf(" 3. Delete a node from the beginning\n");
        printf(" 4. Print the existing list\n");
        printf(" 5. Exit\n\n");
        printf("Enter your choice: ");
        if (!readInt(&choice))
        {
            printf("\nInvalid input. Please enter a number.");
            getch();
            continue;
        }
        printf("\n");
        switch (choice)
        {
        case 1:
            head = createList(head);
            break;
        case 2:
            printf("Enter the data to be inserted: ");
            if (readInt(&x))
            {
                head = Insert_beg(head, x);
                printf("Node inserted.");
            }
            else
                printf("Invalid input.");
            break;
        case 3:
            head = Delete_beg(head);
            break;
        case 4:
            PrintList(head);
            break;
        case 5:
            head = freeList(head);
            printf("Exit: Program Finished !!");
            break;
        default:
            printf("Please enter a valid choice: 1, 2, 3, 4, 5");
        }
        if (choice != 5)
        {
            printf("\n\nPress any key to continue...");
            getch();
        }
    } while (choice != 5);
    getch();
}
int readInt(int *value)
{
    int result;
    result = scanf("%d", value);
    if (result != 1)
    {
        while (getchar() != '\n')
            ;
        return 0;
    }
    return 1;
}
node *createList(node *head)
{
    node *p;
    int i, n;
    head = freeList(head);
    printf("Enter the number of nodes: ");
    if (!readInt(&n) || n <= 0)
    {
        printf("Invalid number of nodes.");
        return (NULL);
    }
    printf("Enter the data: ");
    for (i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            p = head = (node *)malloc(sizeof(node));
        }
        else
        {
            p->next = (node *)malloc(sizeof(node));
            p = p->next;
        }
        p->next = NULL;
        scanf("%d", &(p->data));
    }
    printf("List created.");
    return (head);
}
node *Insert_beg(node *head, int x)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = head;
    head = p;
    return (head);
}
node *Delete_beg(node *head)
{
    node *p;
    if (head == NULL)
    {
        printf("Empty Linked List");
        return (head);
    }
    p = head;
    head = head->next;
    printf("Deleted element is: %d", p->data);
    free(p);
    return (head);
}
node *freeList(node *head)
{
    node *p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
    }
    return (NULL);
}
void PrintList(node *head)
{
    node *p;
    if (head == NULL)
    {
        printf("Empty Linked List");
        return;
    }
    printf("[ ");
    for (p = head; p != NULL; p = p->next)
    {
        printf("%d \t", p->data);
    }
    printf(" ]");
}