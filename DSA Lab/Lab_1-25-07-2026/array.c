#include <stdio.h>

void insertion();
void deletion();
void traversal();

int arr[10], size = 0;

int main()
{
    char choice;
    while (1)
    {
        printf("\n======================================================");
        printf("\nWhich operation do you want to perform?\n");
        printf("press 'i' or 'I' for Insertion\n");
        printf("press 'd' or 'D' for Deletion\n");
        printf("press 't' or 'T' for Traversal\n");
        printf("press 'e' or 'E' to Exit\n");
        printf("Choice:-  ");

        scanf(" %c", &choice);

        if (choice == 'i' || choice == 'I')
        {
            insertion();
        }
        else if (choice == 'd' || choice == 'D')
        {
            deletion();
        }
        else if (choice == 't' || choice == 'T')
        {
            traversal();
        }
        else if (choice == 'e' || choice == 'E')
        {
            printf("\n\nYou have exited the code!!\n");
            break;
        }
        else
        {
            printf("Invalid Choice!!\n");
        }
    }
    return 0;
}

void insertion()
{
    int no;
    if (size == 0)
    {
        printf("\nYour array is empty!\n");
        printf("\nEnter the no of insertion that you want to insert in array btw(1 to 10)\n");
        scanf("%d", &no);
        printf("Enter the values --- ");
        for (int i = 0; i < no; i++)
        {
            scanf("%d", &arr[i]);
            size++;
        }
    }
    else if (0 < size && size < 10)
    {
        printf("\nyour array has %d Empty space!\n", 10 - size);
        printf("\nEnter the no of integer that you want to insert in array btw(1 to %d)\n", 10 - size);

        while (1)
        {
            scanf("%d", &no);
            if (no <= 10 - size)
            {
                printf("Enter the values ---");
                int condition = size;
                for (int i = condition; i < condition + no; i++)
                {
                    scanf("%d", &arr[i]);
                    size++;
                }
                break;
            }
            else
            {
                printf("Enter the value btw(1 to %d)\n", 10 - size);
            }
        }
    }
    else if (size == 10)
    {
        printf("Your array is full!!\n you can't insert\n");
    }
    else
    {
        printf("Please enter btw 1 to 10\n");
    }
}

void deletion()
{

    if (size > 0)
    {
        traversal();
        int item, check = 1;

        printf("\nEnter the element that u want to delete!\n");
        scanf("%d", &item);
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == item)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                printf("\nThe element is deleted!!\n");
                size--;
                check = 0;
                break;
            }
        }
        if (check)
        {
            printf("\nThe element is not present in the array!!\n");
        }
        traversal();
    }
    else
    {
        printf("\nNo element in array for deletion!!\n");
    }
}

void traversal()
{
    printf("\nYour array is here:-\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
