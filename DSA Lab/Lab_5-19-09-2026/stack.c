#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow: Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("Pushed %d onto stack\n", value);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow: Cannot pop from empty stack\n");
        return -1;
    }
    return stack[top--];
}


void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    
    printf("Popped: %d\n", pop());
    display();
    
    
    push(40);
    push(50);
    display();
    
    return 0;
}