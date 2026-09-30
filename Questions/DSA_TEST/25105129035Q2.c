#include <stdio.h>

int fib_re(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib_re(n - 1) + fib_re(n - 2);
}

int fib_arr(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int arr[100];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int main()
{
    int choice, n, looper = 1;

    while (looper)
    {
        printf("Enter the choice through which you want to calculate the fibo!!\n");
        printf("1. recursive\n");
        printf("2. array method\n");
        printf("3. Exit\n");
        printf("Enter the choice:-\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter how many terms that you want(Recursive Method)--\n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", fib_re(i));
            }
            printf("\n");
            break;

        case 2:
            printf("Enter how many terms that you want(Array Method)--\n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", fib_arr(i));
            }
            printf("\n");
            break;

        case 3:
            printf("You have Exited\n");
            looper = 0;
            break;

        default:
            printf("Invalid choice\n!!");
            break;
        }
    }
}