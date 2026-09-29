#include <stdio.h>
#include <limits.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

void push(int n);
int pop();
void display();


void push(int n)
{
    if (top == SIZE - 1)
    {
        printf("Stack Over Flow!!!\n");
        return;
    }
    stack[++top] = n;
    printf("%d is pushed in stack\n", n);
}

int pop()
{
    if (top == -1)
    {
        printf("Stack UnderFlow!!!\n");
        return INT_MIN;
    }
    printf("%d is poped from stack\n", stack[top]);
    return stack[top--];
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Printing stack form bottom to top....\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d, ", stack[i]);
    }
    printf("\n");
}


int main(){
    
    printf("Enter a Postfix Expression -- ");
char exp[SIZE];
fgets(exp, SIZE, stdin);

    printf("%s",exp);


    int i= 0;
    while(exp[i] != '\0' && exp[i] != '\n'){
        if(exp[i] == '0' || exp[i] == '1' || exp[i] == '2' || exp[i] == '3' || exp[i] == '4' || exp[i] == '5' || exp[i] == '6' || exp[i] == '7' || exp[i] == '8' || exp[i]=='9'){
            push(exp[i] - '0');
        }
        if(exp[i] == '/' || exp[i] == '*' || exp[i] == '+' || exp[i] == '-'  ){
            // assci value of '+' = 43
            if (exp[i]== '+'){
                int b = pop();
                int a = pop();
                if(a == INT_MIN || b== INT_MIN)break;
                push(a + b);
            }
            // assci value of '-' = 45
            if (exp[i] == '-'){
                int b = pop();
                int a = pop();
                if(a == INT_MIN || b== INT_MIN)break;
                push(a - b);
            }
            // assci value of '*' = 42
            if (exp[i] == '*'){
                int b = pop();
                int a = pop();
                if(a == INT_MIN || b== INT_MIN)break;
                push(a * b);
            }
            // assci value of '/' = 47
            if (exp[i] == '/'){
                int b = pop();
                int a = pop();
                if(a == INT_MIN || b== INT_MIN)break;
                push(a / b);
            }
        }

        i++;

    }
    if(top == 0){
    printf("=======\n");
    printf("Solution : %d\n",stack[top]);
    printf("=======\n");
    }
    else{
        printf("Invalid Postfix expression");
    }
}