#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100
int i,j;
int printTable(char x[], char y[], int number[][max],char character[][max])
{
    int lengthX = strlen(x);
    int lengthY = strlen(y);
    printf("\t\t\t");
    for(i = 0; i < lengthY; i++)
        printf("%c\t", y[i]);
    printf("\n-------------------------------------------------------------------------------------\n");
    printf("\t\t");
    for(i = 0; i <= lengthY; i++)
        printf("%d\t",i);
    for(i = 0; i<=lengthX; i++) {
        if(i == 0) 
            printf("\n\t%d\t", i);
        else 
            printf("\n%c\t%d\t", x[i-1], i);
        for(j = 0; j <= lengthY; j++) {
            printf("%d%c\t", number[i][j],character[i][j]);
        }        
    }
    printf("\nThe Longest Common Subsequence is:");
    return 0;
}
int printLcs(char character[max][max], char x[], int lengthX, int lengthY)
{
    if(lengthX == 0 || lengthY == 0) 
        return 0;
    else if(character[lengthX][lengthY] == 'd') {
        printLcs(character, x, lengthX-1, lengthY-1);
        printf("%c", x[lengthX]);
    } else if(character[lengthX][lengthY] == 'u')
        printLcs(character, x, lengthX-1, lengthY);
    else 
        printLcs(character, x, lengthX, lengthY-1);
}
int lcs(char x[], char y[])
{
    int number[max][max];
    char character[max][max];
    int lengthX = strlen(x);
    int lengthY = strlen(y);
    for(i=0; i<=lengthX; i++)
        number[i][0] = 0;
    for(j=0; i<=lengthY; j++)
        number[0][j] = 0;
    for(i = 1; i<=lengthX; i++) {
        for(j=1; j<=lengthY; j++) {
            if(x[i] == y[j]) {
                number[i][j] = number[i-1][j-1]+1;
                character[i][j] = 'd';
            } else if(number[i-1][j] >= number[i][j-1]) {
                number[i][j] = number[i-1][j];
                character[i][j]= 'u';
            } else {
                number[i][j] = number[i][j-1];
                character[i][j] = 'l';
            }
        }
    }
    printTable(x, y, number, character);
    printLcs(character, x, lengthX, lengthY);
    return 0;
}
int main()
{
    char x[max], y[max];
    printf("Enter the first character sequence: ");
    scanf(" %s", &x);
    printf("Enter the Second character sequence: ");
    scanf(" %s", &y);
    printf("Your Sequences are:\n");
    printf("X: <");
    for(i = 0; i<strlen(x); i++)
        printf("%c\t", x[i]);
    printf(">\n");
    printf("Y: <");
    for(j = 0; j<strlen(y); j++)
        printf("%c\t", y[j]);
    printf(">\n\n");
    lcs(x, y);
}
