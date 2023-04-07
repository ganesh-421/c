#include<stdio.h>
#define max 100
int i, j;
int merge(int array[], int low, int mid, int high) 
{
    int k, b[max]; i = low; j = mid + 1;
    for(k = low; k <= high; k++) {
        if(i > mid) {
            b[k] = array[j];
            j++;
        } else if(j > high) {
            b[k] = array[i];
            i++;
        } else if(array[i] < array[j]) {
            b[k] = array[i];
            i++;
        } else {
            b[k] = array[j];
            j++;
        }
    }
    for(k = low; k<=high; k++) {
        array[k] = b[k];
    }
}
int* sort(int array[], int low, int high)
{
    int mid;
    if(low < high) {
        mid = (low + high)/2;
        sort(array, low, mid);
        sort(array, mid+1, high);
        merge(array, low, mid, high);
    }
    return array;
}
void printArray(int array[], int size) {
    for(i = 0; i < size; i++) {
        printf("\t%d", array[i]);
    }
}
int main()
{
    int array[max],size;
    printf("-------------------Merge Sort Demo--------------------\n\n");
    printf("Note:Number of elements must be:\n-->less than 100\n-->+ve integer\n");
    printf("Please Enter No. of elements you want to sort: ");
    scanf("%d", &size);
    printf("Please Enter %d elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &array[i]);
    printf("Your Input is: ");
    printArray(array, size);
    printf("\nSorted array: "); 
    printArray(sort(array, 0, size-1), size);
    return 0;
}