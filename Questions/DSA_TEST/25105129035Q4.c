#include <stdio.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(char value) {
    if (isFull()) {
        printf("Stack Overflow: Cannot push %c\n", value);
        return;
    }
    stack[++top] = value;
    printf("Pushed %c onto stack\n", value);
}

char pop() {
    if (isEmpty()) {
        printf("Stack Underflow: Cannot pop from empty stack\n");
        return -1;
    }
    return stack[top--];
}

char peek(){
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top];
    
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int checker(char a){
    if (a == ')') return '(' == peek();
    if (a == ']') return '[' == peek();
    if (a == '>') return '<' == peek();
}

int main() {
    int i = 0;

    printf("Enter the ");
    char str[100];
    fgets(str,100,stdin);

    int check = 1;

    while (str[i] != '\n' )
    {
        if (
            str[0] == ')' ||
            str[0] == ']' ||
            str[0] == '>' 
        ){
        check = 0;
        break;
        }
        else if (
            str[i] == '(' ||
            str[i] == '[' ||
            str[i] == '<' 
        ){
            push(str[i]);
        }
        else if (
            str[i] == ')' ||
            str[i] == ']' ||
            str[i] == '>' 
        ){
        if (checker(str[i])){
            pop();
        }
        else{
            check =0;
            break;
        }
        }
        i++;
    }

    if (isEmpty() && check){
        printf("Valid Parenthesis..\n");
    }
    else{
        printf("Invalid Parenthesis..\n");
    }
    

    
    return 0;
}