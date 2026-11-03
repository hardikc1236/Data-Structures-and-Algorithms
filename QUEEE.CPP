#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100
#define THRESHOLD 40.0

float Q[MAX];
int FRONT = -1, REAR = -1;
int n;

void flush_input()
{
    while (getchar() != '\n')
        ;
}

void insert()
{
    float temp;

    if (REAR >= n - 1)
    {
        printf(" Queue Overflow ! Process some readings first.\n");
    }
    else
    {
        printf(" Enter temperature reading (in C): ");
        if (scanf("%f", &temp) != 1)
        {
            flush_input();
            printf(" Invalid input! Please enter a number.\n");
            return;
        }
        REAR++;
        Q[REAR] = temp;
        if (FRONT == -1)
        {
            FRONT = 0;
        }
        printf(" Reading %.1f C stored in the queue.\n", temp);
    }
}

void process_one()
{
    float temp;

    if (FRONT == -1)
    {
        printf(" Queue Underflow ! No readings to process.\n");
        return;
    }

    temp = Q[FRONT];
    printf(" Processing reading: %.1f C\n", temp);

    if (temp > THRESHOLD)
    {
        printf(" *** HEATWAVE ALERT! %.1f C exceeds the threshold of %.1f C ***\n",
               temp, THRESHOLD);
    }
    else
    {
        printf(" Normal: temperature is within the safe limit.\n");
    }

    FRONT++;
    if (FRONT > REAR)
    {
        FRONT = -1;
        REAR = -1;
    }
}

void process_all()
{
    int alerts = 0, count = 0;
    float temp;

    if (FRONT == -1)
    {
        printf(" Queue is empty ! No readings to process.\n");
        return;
    }

    while (FRONT != -1)
    {
        temp = Q[FRONT];
        count++;
        if (temp > THRESHOLD)
        {
            printf(" Reading %d: %.1f C  -> HEATWAVE ALERT!\n", count, temp);
            alerts++;
        }
        else
        {
            printf(" Reading %d: %.1f C  -> Normal\n", count, temp);
        }
        FRONT++;
        if (FRONT > REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
    }
    printf("\n Processed %d reading(s), %d heatwave alert(s).\n", count, alerts);
}

void display()
{
    int i;

    if (FRONT == -1)
    {
        printf(" Queue is empty ! \n");
    }
    else
    {
        printf(" Readings in the queue (front to rear):\n");
        for (i = FRONT; i <= REAR; i++)
        {
            printf("  %.1f C", Q[i]);
            if (Q[i] > THRESHOLD)
                printf("  (above threshold)");
            if (i == FRONT)
                printf("  <- FRONT");
            if (i == REAR)
                printf("  <- REAR");
            printf("\n");
        }
    }
}

void main()
{
    int choice;

    clrscr();
    printf("=== Temperature Reading Queue ===\n");
    printf("Heatwave threshold: %.1f C\n", THRESHOLD);

    do
    {
        printf("\nEnter the size of Queue (Maximum size = %d): ", MAX);
        if (scanf("%d", &n) != 1)
        {
            flush_input();
            n = 0;
        }
        if (n < 1 || n > MAX)
            printf("Invalid size! Enter a value between 1 and %d.\n", MAX);
    } while (n < 1 || n > MAX);

    while (1)
    {
        printf("\n Queue Operations available: \n");
        printf("\t1. Insert reading\n");
        printf("\t2. Process next reading\n");
        printf("\t3. Process all readings\n");
        printf("\t4. Display queue\n");
        printf("\t5. Exit\n");
        printf("\n Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            flush_input();
            printf(" Invalid input! Please enter a number 1-5.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                process_one();
                break;
            case 3:
                process_all();
                break;
            case 4:
                display();
                break;
            case 5:
                printf(" Exit: Program Finished !! \n");
                printf(" Press any key to close.");
                getch();
                exit(0);
            default:
                printf(" Please enter a valid choice 1-5.\n");
        }
    }
}