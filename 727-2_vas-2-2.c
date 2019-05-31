#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, sum = 0;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &b);
        sum += (i%2)*b*b*b;
    }
    printf("%d", sum);
    return 0;
}

