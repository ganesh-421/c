#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define max 100
int i, j;
int search(int array[], int size, int key, bool repeat)
{
    int pos = -1;
    char c;
    if(repeat) { //to demonstrate multiple search
        // linear search actually starts from here
        printf("\nPlease Enter The Item you want to search: ");
        scanf("%d", &key);
        for(i = 0; i<size; i++) {
            if(key == array[i])
                pos = i;
        }
        if(pos == -1)
            printf("Search Item Not Found!");
        else 
            printf("The search item is %dth Element",pos+1);
        printf("\nDo you want to search another item?(y/n): ");
        scanf(" %c", &c);
        if(toupper(c) == toupper('y'))
            search(array, size, key, true);
        else 
            search(array, size, key, false);
    }
    return 0;
    
    
}
void printArray(int array[], int size) {
    for(i = 0; i < size; i++) {
        printf("\t%d", array[i]);
    }
}
int main()
{
    int array[max] = {5,4,3,2,1};
    int size = 5;
    printf("-------------------Linear Search Demo--------------------\n\n");
    printf("The list is: ");
    printArray(array, size);
    search(array, size, 0, true);
    return 0;
}