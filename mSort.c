#include<stdio.h>

void merge(int[], int, int, int);
void merge_sort(int[], int, int);

int main()
{
    int a[] = {-1,-2,-2,3,9,7,0,34,-1,23,40,9,4};
    int i = 0;
    int size = (sizeof(a)/sizeof(a[0]));

    merge_sort(a, 0, size-1);

    printf("\n Sorted array \n");

    for(i = 0; i < size; i++)
        printf("%d ",a[i]);

    return 0;
}

void merge_sort(int a[], int low, int high){

    int mid;

    if( low < high){

        mid = (low+high)/2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high){

    int i= low;
    int j = mid+1;
    int k = 0;

    int m[high-low+1];

    while( i <= mid && j <= high){

        if(a[i] < a[j])
            m[k++] = a[i++];
        else
            m[k++] = a[j++];
    }

    while( i <= mid)
        m[k++] = a[i++];
    while(j<= high)
        m[k++] = a[j++];

    i=0;

    for( i=0, j=low; i < (high-low+1); i++,j++){

        a[j] = m[i];
    }
}