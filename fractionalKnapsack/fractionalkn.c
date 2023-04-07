#include<stdio.h>
#define max 100
int i, j;
void printTable(int noOfItems, float wtOfItem[], float costOfItem[],float cpw[])
{
    printf("\nItem\tweight\t\tcost\t\tcpw");
    for(i=0; i<noOfItems; i++) {
            printf("\n%d\t%f\t%f\t%f", i, wtOfItem[i],costOfItem[i], cpw[i]);
    }

}
int knapSack(float capOfkn, int noOfItems, float costOfItems[], float wtOfItems[], float cpw[])
{
    float remCap = capOfkn; i = 0;j=0;
    float  knItemCost = 0;
    while (i < noOfItems)
    {
        if(remCap >= wtOfItems[i]){
           remCap-=wtOfItems[i];
           knItemCost += costOfItems[i];
        }
        i++;
    }
    if(remCap > 0) {
        while (j < noOfItems) {
            if(remCap >= cpw[j]) {
                remCap -= 1.000;
                knItemCost+=cpw[j];
            }
            j++;
        }
    }
    printf("\nTotal Cost of Items Added In Knapsack:%f\n", knItemCost);

}
int sum(int a, int b) {
	return a+b;
}
int main() 
{
	int k;
	k= sum(4,5);
	printf("The ssum is %d", k);
    float wtOfItems[max], costOfItems[max],capOfKn, cpw[max];
    int noOfItems;
    printf("Enter The Capacity Of Knapsack: ");
    scanf("%f", &capOfKn);
    printf("Enter The Total no. Of Items: ");
    scanf("%d", &noOfItems);
    printf("Enter Weights of %d Items in order:", noOfItems);
    for(i=0; i < noOfItems; i++)
        scanf("%f", &wtOfItems[i]);
    printf("Enter Costs of %d Items in order:", noOfItems);
    for(i=0; i < noOfItems; i++)
        scanf("%f", &costOfItems[i]);
    // calculate cost per unit weight
    for(i = 0; i< noOfItems; i++)
        cpw[i] = costOfItems[i]/wtOfItems[i];
    printTable(noOfItems, wtOfItems, costOfItems, cpw);
    knapSack(capOfKn, noOfItems, costOfItems, wtOfItems, cpw);
}
