#include <stdio.h>

void merge(int a[], int b[], int n, int m)
{

    int c[n + m];
    int i, j,k;

    for (i = 0, j = 0,k=0; i < n && j < m;)
    {

        if (a[i] <= b[j])
        {
            c[k] = a[i];
            i++;k++;
        }
        else if (a[i] >= b[j])
        {
            c[k] = b[j];
            j++;k++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++;k++;
    }

    for (i = 0; i < (n+ m); i++)
        printf("%d ", c[i]);
}

int main()
{

    int a[] = {1, 2, 3, 8, 9,19,20,21,22,22,22};
    int b[] = {3, 8, 9, 10, 11, 12, 14};
    int i = 0;

    for (i = 0; i < 11; i++)
        printf("%d ", a[i]);

    printf("\n\n");

    for (i = 0; i < 7; i++)
        printf("%d ", b[i]);

    printf("\n\n");

    merge(a, b, 11, 7);

    return 0;
}