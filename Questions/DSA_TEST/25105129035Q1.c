#include<stdio.h>

int arr[6];
int top = -1;

void initialisation(){
    arr[0] = 20;
    arr[1] = 40;
    arr[2] = 150;
    arr[3] = 60;
    arr[4] = 35;
    arr[5] = 50;
    top += 6;
}

void insert(int p ,int n){

    if (p<=6 && p>0)
    {
        arr[p - 1] = n;
    }
    else 
    {
        printf("Cant insert");
    }
    
}

int search(int n){

    if(top == -1){
        printf("Array empty \n");
        return -1;
    }
    for(int i = 0; i <= top; i++){
        if (arr[i] == n){
            return 1;
        }
    }
    return 0;
}

void delete(int p){
    if (p <= 6 && p >=1){
        for (int i = p - 0; i < top; i++){
            arr[i] = arr[i+1];
        }
        top--;
        printf("Element Deleted\n");
    }
    else{
        printf("There is no element in the array at that position\n");
    }
    
    

}

void display(){

    printf("Display--\n");
    for(int i =0 ; i <= top; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int choice,flag = 1;
    initialisation();

    while (flag)
    {
        int p,n;

        printf("\n\n========Code=========");
        printf("\n1. Add a number at a certain position\n");
        printf("2. Remove a quantity from a specified location\n");
        printf("3. Find whether a particular quantity exists\n");
        printf("4. Display all current quantities\n");
        printf("5. Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the position in which you want to insert\n");
            scanf("%d",&p);
            printf("Enter the element you want to insert \n");
            scanf("%d",&n);

            insert(p,n);
            
            break;
        case 2:
            
            printf("Enter the location of the Element That you want to DELETE\n");
            scanf("%d",&p);
            delete(p);
            break;

        case 3:
            
            printf("Enter the element you want to search.\n");
            scanf("%d",&n);
            if(search(n)){
                printf("The Element Exist!!\n");
            }
            else {
                printf("Element does not exist in array\n");
            }
            break;
            
        case 4:
        display();
        break;
        
        case 5:
        printf("You have exited the code\n");
        flag = 0;
        break;
        
        default:
        printf("invalid input\n");
        flag =0;
            break;
        }

    }

}