#include<stdio.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

void push(int n);
int pop();
void display();


int main(){


    push(20);
    push(0);
    push(45);
    pop();
    push(80);
    display();


    return 0;
}

void push( int n){
    if(top == SIZE - 1){
        printf("Stack Over Flow!!!\n");
        return;
    }
    stack[++top] = n;
    printf("%d is pushed in stack\n",n);
}

int pop(){
    if(top == -1){
        printf("Stack UnderFlow!!!\n");
        return -1;
    }
    printf("%d is poped from stack\n",stack[top]);
    return stack[top--];
}

void display(){
    if(top == -1){
        printf("Stack is Empty\n");
        return;
    }
    printf("printing stack form bottom to top....\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t",stack[i]);
    }
    printf("\n");
}
