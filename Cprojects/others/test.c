#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main() {
	char *ch;
	ch = malloc(sizeof(char));
	ch = "Hello World";
	if(ch == "Hello World")
	printf("%s", ch);
} 

