#include <stdio.h>

void ToH(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c --> %c\n", a, c);
        return;
    }
    ToH(n - 1, a, c, b);
    ToH(1, a, b, c);
    ToH(n - 1, b, a, c);
}

int main()
{
    int n;

    printf("Enter the no of blocks that you want to move from block A to B:\n");

    scanf("%d", &n);

    ToH(n, 'A', 'B', 'C');

    return 0;
}