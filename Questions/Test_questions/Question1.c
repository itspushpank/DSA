#include<stdio.h>

#define MAX 100
int arr[MAX], top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX - 1;
}

void insertMarks(int n){
    if (isFull()){
        printf("Array is full!!\n");
        return;
    }
    arr[++top] = n;
    printf("Marks added to array...\n");

}

void updateMarks(int index, int n){
    if(isFull()){
        printf("Array is full !!\n");
        return;
    }
    
    if (index > top){
        printf("No Element at this index to update !!\n");
        return;
    }
    arr[index] = n;
}

void deleteMarks(int n){
    if(isEmpty()){
        printf("Array is empty cant delete!!\n");
        return;
    }
    int check = 0;

    for(int i = 0; i <= top; i++){
        
        if (arr[i] == n){
            for(int j = i; j < top; j++){
                arr[j] = arr[j + 1];
            }
            top--;
            check = 1;
            printf("Element Deleted Successfully!1\n");
            break;
        }
    }

    if(!check){
        printf("Element Not Found!!\n");
    }

}

void displayMarks(){
    if(isEmpty()){
        printf("Array is Empty!1\n");
        return;
    }
    printf("------------------------Marks----------------------\n");
    for(int i = 0; i <= top; i++){
        printf("%d ",arr[i]);
    }
}

void initalisation(){
    arr[0] = 72;
    arr[1] = 65;
    arr[2] = 81;
    arr[3] = 56;
    arr[4] = 90;
    arr[5] = 68;

    top += 6;
}

int main(){
    int choice;

    while (1)
    {
        printf("== Student Marks Management ==\n");
        printf("Enter the choice-\n");
        printf("Enter the choice-\n");
        printf("Enter the choice-\n");
        printf("Enter the choice-\n");
        printf("Enter the choice-\n");
        scanf("%d",&choice);
    }
    
}