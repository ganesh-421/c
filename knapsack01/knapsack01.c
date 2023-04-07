#include<stdio.h>
#define max 100
int i, j;
void printTable(int noOfItems, int capOfKn, int wtOfItem[], int costOfItem[],int selectedCost[][max])
{
    printf("\ni\twt\tcost\t\t\tWeight Of Knapsack--->\n");
    printf("-------------------------------------------------------------------\n");
    printf("\t\t\t");
    for(i = 0; i<=capOfKn; i++) 
        printf("%d\t",i);
    for(i = 0; i<=noOfItems; i++) {
        printf("\n%d\t%d\t%d\t",i, wtOfItem[i], costOfItem[i]);
        for(j = 0; j <= capOfKn; j++) {
            printf("%d\t", selectedCost[i][j]);
        }        
    }

}
int knapSack(int capOfkn, int noOfItems, int costOfItems[], int wtOfItems[])
{
    int totalCost = 0; int totalWeight = 0;
    int selectedCost[max][max];
    for(j = 0; j <= capOfkn; j++)
        selectedCost[0][j] = 0;//first row all 0
    for(i = 1; i <= noOfItems; i++)
        selectedCost[i][0] = 0; //first column all 0
    for(i = 1; i<=noOfItems; i++) {
        for(j = 1; j<=capOfkn; j++) {
            if(wtOfItems[i] <= j) {
                if(selectedCost[i-1][j-wtOfItems[i]] + costOfItems[i] > selectedCost[i-1][j])
                    selectedCost[i][j] = selectedCost[i-1][j-wtOfItems[i]]+costOfItems[i];
                else 
                    selectedCost[i][j] = selectedCost[i-1][j];
            } else
                selectedCost[i][j] = selectedCost[i-1][j];
        }
    }
    printTable(noOfItems, capOfkn, wtOfItems, costOfItems, selectedCost);
    printf("\n\nItems To Be Added In Knapsacks Are:\n");
    i=noOfItems; j=capOfkn;
    while(i > 0 && j > 0) {
        if(selectedCost[i][j] == selectedCost[i-1][j])
            i--;
        else {
            printf("%dth Item with %d wt and %d Cost\n", i, wtOfItems[i], costOfItems[i]);
            totalCost += costOfItems[i]; totalWeight +=wtOfItems[i];
            i--;
            j-=wtOfItems[i];
        }
    }
    printf("\nTotal Profit otained: %d \n Total Weight added: %d", totalCost, totalWeight);
    return 0;
}
int main() 
{
    int noOfItems,wtOfItems[max], costOfItems[max],capOfKn;
    printf("Enter The Capacity Of Knapsack: ");
    scanf("%d", &capOfKn);
    printf("Enter The Total no. Of Items: ");
    scanf("%d", &noOfItems);
    printf("Enter Weights of %d Items in order:", noOfItems);
    printf("\n(Input starts from 0 to %d, so please Enter 0 first and then proceed) ",noOfItems);
    for(i=0; i <= noOfItems; i++)
        scanf("%d", &wtOfItems[i]);
    printf("Enter Costs of %d Items in order:", noOfItems);
    printf("\n(Input starts from 0 to %d, so please Enter 0 first and then proceed) ",noOfItems);
    for(i=0; i <= noOfItems; i++)
        scanf("%d", &costOfItems[i]);
    knapSack(capOfKn, noOfItems, costOfItems, wtOfItems);
}