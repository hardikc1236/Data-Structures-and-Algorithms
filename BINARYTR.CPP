#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node {
    char city[20];
    int temp;
    struct node *left, *right;
};

struct node *insert(struct node *root, char *city, int temp)
{
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        strcpy(root->city, city);
        root->temp = temp;
        root->left = root->right = NULL;
    }
    else if (temp < root->temp)
        root->left = insert(root->left, city, temp);
    else
        root->right = insert(root->right, city, temp);
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%-15s %d C\n", root->city, root->temp);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL) {
        printf("%-15s %d C\n", root->city, root->temp);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%-15s %d C\n", root->city, root->temp);
    }
}

void main()
{
    struct node *root = NULL;
    int ch, temp;
    char city[20];

    while (1) {
        clrscr();
        printf("WEATHER MONITORING SYSTEM\n");
        printf("1. Add reading\n");
        printf("2. Inorder (sorted by temperature)\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("City: ");
                scanf("%s", city);
                printf("Temperature: ");
                scanf("%d", &temp);
                root = insert(root, city, temp);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\nPress any key...");
        getch();
    }
}