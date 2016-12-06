#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char*, char*);

int main(void){
	char* a = "Hello,";
	char* b = "world!";
	char* string = concat(a, b);
	printf("%s\n", string);
	return 0;
}

char* concat(char* a, char* b){
	int i;
	int aLen = strlen(a);
	int bLen = strlen(b);
	char* string = (char*)malloc(aLen + bLen + 1);
	for (i = 0; i < aLen; i++){
		string[i] = a[i];
	}
	string[i] = ' ';
	for (i = 0; i < bLen; i++){
		string[aLen + i + 1] = b[i];
	}
	return string;
}