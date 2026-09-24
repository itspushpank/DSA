#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX_SIZE - 1;
}

void push(char value)
{
    if (isFull())
    {
        printf("Stack Overflow: Cannot push %c\n", value);
        return;
    }
    stack[++top] = value;
    // printf("Pushed %c onto stack\n", value);
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow: Cannot pop from empty stack\n");
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--)
    {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main()
{

    // char str[50];
    // scanf("%s",&str);
    printf("Enter your string of Parentheses\n");
    char *str;
    gets(str);

    int val = 1;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[0] == ')')
        {
            // printf("\nInvalid!!\n");
            val = 0;
            break;
        }

        if (str[i] == '(')
        {
            push('(');
        }

        if (str[i] == ')')
        {
            if (!isEmpty())
                pop();
            else
            {
                // printf("\nInvalid!!\n");
                val = 0;
                break;
            }
        }
    }

    if (val && isEmpty())
    {
        printf("\nValid parentheses!!");
    }
    else
        printf("\nInvalid!!\n");

    return 0;
}