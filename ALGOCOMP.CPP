#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int id;
    char name[30];
    float score;
};

void main() {
    struct Student s[100], temp;
    int n, i, j, key, choice, found;

    clrscr();
    srand((unsigned int)time(NULL));

    printf("======================================\n");
    printf("     STUDENT RECOMMENDATION SYSTEM    \n");
    printf("======================================\n");
    printf("Enter number of students (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of students.\n");
        getch();
        return;
    }

    for (i = 0; i < n; i++) {
        s[i].id = 1001 + i;
        sprintf(s[i].name, "Student_%d", i + 1);
        s[i].score = (float)(rand() % 1000) / 10.0;
    }

    while (1) {
        printf("\n================ MENU ================\n");
        printf("1. Display All Students\n");
        printf("2. Rank Students by Score (Selection Sort)\n");
        printf("3. Search Student by ID (Linear Search)\n");
        printf("4. Exit\n");
        printf("======================================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("\nExiting System. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("\n--- Unsorted Student List ---\n");
                printf("ID\tName\t\tScore\n");
                printf("-----------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t%-12s\t%.2f\n", s[i].id, s[i].name, s[i].score);
                }
                break;

            case 2:
                for (i = 0; i < n - 1; i++) {
                    for (j = i + 1; j < n; j++) {
                        if (s[i].score < s[j].score) {
                            temp = s[i];
                            s[i] = s[j];
                            s[j] = temp;
                        }
                    }
                }
                printf("\n--- Students Ranked by Score ---\n");
                printf("Rank\tID\tName\t\tScore\n");
                printf("--------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t%d\t%-12s\t%.2f\n", i + 1, s[i].id, s[i].name, s[i].score);
                }
                break;

            case 3:
                printf("\nEnter Student ID to search (1001 to %d): ", 1000 + n);
                scanf("%d", &key);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (s[i].id == key) {
                        printf("\n[RESULT] Student Found!\n");
                        printf("ID   : %d\n", s[i].id);
                        printf("Name : %s\n", s[i].name);
                        printf("Score: %.2f\n", s[i].score);
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("\n[RESULT] Student with ID %d not found.\n", key);
                }
                break;

            default:
                printf("\nInvalid choice! Please choose options 1 to 4.\n");
                break;
        }
    }

    getch();
}