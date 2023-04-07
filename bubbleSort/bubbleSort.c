#include<stdio.h>
#define max 100
int i, j;
int* sort(int array[], int size)
{
    int temp;
    for(i = 0; i<size-1; i++) {
        for(j = 0; j< size-i-1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
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
    printf("-------------------Bubble Sort Demo--------------------\n\n");
    printf("Note:Number of elements must be:\n-->less than 100\n-->+ve integer\n");
    printf("Please Enter No. of elements you want to sort: ");
    scanf("%d", &size);
    printf("Please Enter %d elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &array[i]);
    printf("Your Input is: ");
    printArray(array, size);
    printf("\nSorted array: "); 
    printArray(sort(array, size), size);  
    return 0;
}