#include <stdio.h>
#include <stdlib.h>


int sorting_function(int *arr, int n)
{
    int p, d, buf, loop, iter;
    p = 1247;
    d = (n * 1000) / p;
//printf(" -%d- \n", d);
    if(d < 1)
    {
        d = 1;
    }

    iter = 0;
    for(int i = 0; i < n; i++)
    {
        if(d == 1)
        {
            loop = 0;
        }
        for(int j = 0; j < n - d; j++)
        {
            if(arr[j] > arr[j+d])
            {
                iter++;
                buf = arr[j];
                arr[j] = arr[j+d];
                arr[j+d] = buf;
                if(d == 1)
                {
                    loop = 1;
                }
            }
        }
//print_arr(arr, n);
        if(d == 1 && loop == 0)
        {
            break;
        }

        d = (d * 1000) / p;
        if(d < 1)
        {
            d = 1;
        }
//printf(" -%d- \n", d);
    }

    return iter;
}
void print_arr(int *arr, int n)
{
    int i;
    for(i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
}

int main()
{
    int n, it;
    scanf("%d", &n);
    int *arr;
    arr = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //print_arr(arr, n);

    it = sorting_function(arr, n);
    //printf("%d\n", it);

    print_arr(arr, n);


    return 0;
}

