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

void print_arr(int *arr, int n)
{
    int i;
    for(i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
}


void sw(int *a, int l, int r)
{
    int buf;
    buf = a[l];
//printf("%d", buf);
    a[l] = a[r];
//printf("%d", l);
    a[r] = buf;
//printf("%d", r);
}

void check_elem(int *a, int i, int n)
{
    if(2*i+2 < n)
    {
        if(2*i+1 < n && a[i] < a[2*i+1] && a[2*i+1] > a[2*i+2])
        {
            sw(a, i, 2*i+1);
            check_elem(a, 2*i+1, n);
        }
        else if(a[i] < a[2*i+2] && a[2*i+2] > a[2*i+1])
        {
           sw(a, i, 2*i+2);
           check_elem(a, 2*i+2, n);
        }
    }
    else if(2*i+1 < n && a[i] < a[2*i+1])
    {
        sw(a, i, 2*i+1);
    }
}

int sorting_function(int *a, int n)
{
    int i, stat = 0;
    //первое упорядочивание
    for(i = (n)/2 ; i >= 0; i--)
    {
//printf("-%d-  ", i);
        if(2*i+2 < n)
        {
            if(2*i+1 < n && a[i] < a[2*i+1] && a[2*i+1] > a[2*i+2])
            {
                sw(a, i, 2*i+1);
                check_elem(a, 2*i+1, n);
            }
            else if(a[i] < a[2*i+2] && a[2*i+2] > a[2*i+1])
            {
               sw(a, i, 2*i+2);
               check_elem(a, 2*i+2, n);
            }
        }
        else if(2*i+1 < n && a[i] < a[2*i+1])
        {
            sw(a, i, 2*i+1);
        }

 //print_arr(a, n);
    }
    // сортировка
    for (i = n - 1; i > 0; i--)
    {
//printf("1_%d- ", i);
//print_arr(a, n);
        sw(a, 0, i);
//printf("2_%d- ", i);
//print_arr(a, n);
        check_elem(a, 0, i);
//printf("3_%d- ", i);
//print_arr(a, n);
    }
    //sw(a, 0, 1);



    return stat;
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

