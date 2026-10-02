#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void initStack() {
    top = -1;
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (isEmpty()) {
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        return -1;
    }
    return stack[top];
}