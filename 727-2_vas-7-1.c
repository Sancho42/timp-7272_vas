#include <stdio.h>
#include <stdlib.h>

void prit_part (int *a, int l, int r)
{
     int i;
    for(i = l; i < r; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[i]);
}

void hswap(int *a, int sup, int i)
{
    int buf;
    buf = a[sup];
    a[sup] = a[i];
    a[i] = a[sup + 1];
    a[sup + 1] = buf;

}

int qs(int *a, int l, int r)
{
    int support;
    support = l;
    for (int i = l + 1; i <= r; i++)
    {
        if(a[i] < a[support])
        {
            hswap(a, support, i);
            support++;
        }
    }

    return support;
}

int sorting_function(int *a, int l, int r)
{
    int i, stat = 0;
    if (l < r)
    {
        //stat++;
        i = qs(a, l, r);
//prit_part(a, l, r);
        sorting_function(a, l, i - 1);
        sorting_function(a, i + 1, r);
    }

    return stat;
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

    it = sorting_function(arr, 0, n - 1);
    //printf("%d\n", it);

    print_arr(arr, n);


    return 0;
}

