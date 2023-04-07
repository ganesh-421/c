#include<stdio.h>
#define max 100
int i, j;
int search(int array[], int left, int right, int key)
{
    if(left == right) {
        if(key == array[left])
            return left;
        else 
            return -1;
    } else {
        i = (left + right)/2;
        if(key == array[i])
            return i;
        else if(key < array[i])
            return search(array, left, i-1, key);
        else 
            return search(array, i+1, right, key);
    }
}
void printArray(int array[], int size) {
    for(i = 0; i < size; i++) {
        printf("\t%d", array[i]);
    }
}
int main()
{
    int array[max] = {1,2,3,4,5};
    int size = 5; int key;
    printf("-------------------Binary Search Demo--------------------\n\n");
    printf("The list is: ");
    printArray(array, size);
    printf("\nPlease Enter The Item you want to search: ");
    scanf("%d", &key);
    j=search(array, 0, size-1, key);
    if(j == -1)
         printf("Search Item Not Found!");
    else 
        printf("The search item %d is %dth Element",key,j+1); 
    return 0;
}