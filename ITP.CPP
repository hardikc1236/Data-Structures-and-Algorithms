#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow");
        return;
    }
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}

int is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' ||
            c == '%' || c == '^');
}

int precedence(char c)
{
    switch (c)
    {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int infix_to_postfix(char infix[], char postfix[])
{
    int i, j;
    char ch, t;

    i = 0;
    j = 0;
    top = -1;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (ch == ' ' || ch == '\t')
        {
            i++;
            continue;
        }

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();

            if (top == -1)
                return 0;

            pop();
        }
        else if (is_operator(ch))
        {
            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) && ch != '^')))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (top != -1)
    {
        t = pop();
        if (t == '(')
            return 0;
        postfix[j++] = t;
    }

    postfix[j] = '\0';
    return 1;
}

void main()
{
    char infix[MAX], postfix[MAX];
    int len;

    clrscr();

    printf("Infix to Postfix Conversion\n");
    printf("---------------------------\n");
    printf("Operators allowed: + - * / %% ^ and ( )\n");
    printf("Operands: single letters or digits\n\n");
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n')
        infix[len - 1] = '\0';

    if (infix_to_postfix(infix, postfix))
        printf("\nPostfix expression: %s", postfix);
    else
        printf("\nInvalid expression: unbalanced parentheses.");

    getch();
}