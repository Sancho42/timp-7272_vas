#include <stdio.h>
#include <stdlib.h>


int sorting_function(int *A, int N)
{
    int i, j, k;
	int t, stat = 0;
	for(k = N / 2; k > 0; k /= 2)
        for(i = k; i < N; i++)
        {
            t = A[i];
            for(j = i; j >= k; j -= k)
            {
                stat++;
                if(t < A[j - k])
                    A[j] = A[j - k];
                else
                    break;
            }
            A[j] = t;
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

    it = sorting_function(arr, n);
    //printf("%d\n", it);

    print_arr(arr, n);


    return 0;
}

