#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char*);

int main(void){
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	printf("%s\n", reverse(str));
	return 0;
}

char* reverse(char* str){
	int i;
	int leng = strlen(str);
	char *string = (char*)malloc(leng);
	for(i = 0; i < leng; i++){
		string[i] = str[leng - i - 1];
	}
	string[leng] = NULL;
	return string;
}