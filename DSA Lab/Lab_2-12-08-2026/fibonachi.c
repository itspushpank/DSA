#include <stdio.h>

int fibo_re(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo_re(n - 2) + fibo_re(n - 1);
}

int fibo_arr(int n)
{

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int arr[n + 1];

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
    int choice, n;

    printf("Enter form what method do you want to calculate fibonachi :\n");
    printf("1. form recursion");
    printf("2. form array method");

    scanf("%d", &choice);

    printf("Enter the term of which fibonachi value you want-\n");
    scanf("%d", &n);

    switch (choice)
    {
    case 1:
        printf("The fibonachi term is %d\n", fibo_re(n));

        break;

    case 2:
        printf("The fibonachi term is %d\n", fibo_arr(n));

        break;

    default:
        printf("Invalid Input\n");
        break;
    }
    return 0;
}
