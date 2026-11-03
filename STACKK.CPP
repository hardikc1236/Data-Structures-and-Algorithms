
#include <stdio.h>
#include <conio.h>

#define N 5
int S[N + 1];           
int TOP = 0;              


void push(int X)
{
    
    if (TOP >= N)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    
    TOP = TOP + 1;
    
    S[TOP] = X;
    
    printf("%d pushed onto the stack\n", X);
}

int pop(int *item)
{
    
    if (TOP == 0)
    {
        printf("STACK UNDERFLOW ON POP\n");
        return 0;
    }
    
    TOP = TOP - 1;
    
    *item = S[TOP + 1];
    return 1;
}


void display()
{
    int i;
    if (TOP == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom):\n");
    for (i = TOP; i >= 1; i--)
    {
        if (i == TOP)
            printf("  %d  <- TOP\n", S[i]);
        else
            printf("  %d\n", S[i]);
    }
}

void main()
{
    int choice, x, item;

    clrscr();
    do
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                if (pop(&item))
                    printf("Popped element: %d\n", item);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
		printf("Press any key to close.");
		getch();
		exit(0);

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    } while (choice != 4);

    getch();
}