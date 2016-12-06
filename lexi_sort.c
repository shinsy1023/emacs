#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 50
#define N       1000

void sort_words(char* [], int);
void swap(char**, char**);

int main(void){
	char *w[N];
	char word[MAXWORD];
	int n;
	int i;

	for (i = 0; scanf("%s", word) == 1; ++i){
		if (!strcmp(word, "exit")) break;
		w[i] = calloc(strlen(word) + 1, sizeof(char));
		strcpy(w[i], word);
	}
	n = i;
	sort_words(w, n);
	for(i = 0; i < n; ++i)
		printf("%s\n", w[i]);
	return 0;
}

void sort_words(char* w[], int n){
	int i, j;

	for(i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			if (strcmp(w[i], w[j]) > 0)
				swap(&w[i], &w[j]);
}

void swap(char** p, char** q){
	char *temp;

	temp = *p;
	*p = *q;
	*q = temp;
}