#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct
{
    int Queue[MAX];
    int front;
    int rear;
} Nqueue  ;

Nqueue* createQueue(){
    Nqueue* q = malloc(sizeof(Nqueue));
    q -> front = -1;
    q -> rear = -1;
    return q;
}

int isEmpty(Nqueue* q){
    return q -> front == -1;
}

int isFull(Nqueue* q){
    return q -> rear == MAX -1;
}

void enQueue(Nqueue* q, int item){
    if(isFull(q)){
        printf("Queue is full.\n");
        return ;
    }
    if(q -> rear == -1){
        q -> Queue[++q -> rear] = item;
        q -> front++;
        printf("Enqueued %d\n",item);
    }
    else 
    {
        q -> Queue[++q -> rear] = item;
        printf("Enqueued %d\n",item);
    }
}

int dequeue(Nqueue* q){
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
        return -1;
    }
    if(q -> front == q -> rear){
        int temp = q -> Queue[q -> front];
        q -> rear = -1;
        q -> front = -1;
        return temp;
    }

    return q -> Queue[++q -> front];


}

void display(Nqueue* q){
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
        return;
    }
    printf("display :-\n");
    for (int i = q -> front; i <= q -> rear; i++)
    {
        printf("%d ",i);
    }
    
}



int main(){

    Nqueue* q = createQueue();





}

