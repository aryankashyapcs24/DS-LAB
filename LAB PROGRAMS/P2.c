#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top == (MAX - 1))
    {
        printf("Stack overflow\n");
    }
    else
    {
        top = top + 1;
        stack[top] = c;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        char temp = stack[top];
        top = top - 1;
        return temp;
    }
}

char peek()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void infixtopostfix(char infix[])
{
    char postfix[MAX];
    int i, j = 0;
    char token;

    for (i = 0; i < strlen(infix); i++)
    {
        token = infix[i];

        if (isalnum(token))
        {
            postfix[j++] = token;
        }
        else if (token == '(')
        {
            push(token);
        }
        else if (token == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1 && peek() == '(')
            {
                pop();
            }
            else
            {
                printf("Invalid expression: mismatched parentheses\n");
            }
        }
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(token))
            {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    while (top != -1)
    {
        if (peek() == '(')
        {
            printf("Invalid expression: mismatched parentheses\n");
            pop();
        }
        else
        {
            postfix[j++] = pop();
        }
    }

    postfix[j] = '\0';
    printf("Postfix expression is: %s\n", postfix);
}

int main()
{
    char infix[MAX];

    printf("Enter a valid infix expression: ");
    fgets(infix, MAX, stdin);

    infixtopostfix(infix);

    return 0;
}
