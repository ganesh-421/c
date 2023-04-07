#include<stdio.h>
#define max 100
int i, j;
int partition(int array[], int left, int right) 
{
    int pivot, temp;
    i= left; j= right; pivot = array[left];
    while( i < j) {
        while(array[i] <= pivot && i <= right)
            i++;
        while(array[j] > pivot && j >= left)
            j--;
        if(i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        temp = array[j];
        array[j] = pivot;
        array[left] = temp;
    }
    return j;
}
int* sort(int array[], int low, int high)
{
    int partitionIndex;
    if(low < high) {
        partitionIndex = partition(array, low, high);
        sort(array, low, partitionIndex-1);
        sort(array, partitionIndex+1, high);
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
    printf("-------------------Quick Sort Demo--------------------\n\n");
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