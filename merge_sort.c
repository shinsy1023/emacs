#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define KEYSIZE 16

void newmergesort(int *, int);
void merge(int*, int*, int*, int, int);
void print_array(char*, int*, int);

int main(void){
	int i, key[] = {4, 3, 1, 67, 55, 8, 0, 4,
		-5, 37, 7, 4, 2, 9, 1, -1};
	print_array("before newmergesort", key, KEYSIZE);
	newmergesort(key, KEYSIZE);
	print_array("after newmergesort", key, KEYSIZE);
	return 0;
}

void newmergesort(int key[], int n){
	int j, k ,m, *w;
	for(m = 1; m < n; m *= 2)
		;
	if(m != n){
		printf("ERROR: Size of the array is not a power of 2 - bye!\n");
		exit(1);
	}
	w = calloc(n, sizeof(int));
	assert(w != NULL);
	for (k = 1; k < n; k *= 2){
		for (j = 0; j < n - k; j += 2 * k)
			merge(key + j, key + j + k, w + j, k, k);
		for (j = 0; j < n; ++j)
			key[j] = w[j];
		print_array("intermediate:", key, KEYSIZE);
	}
	free(w);
}

void merge(int a[], int b[], int c[], int m, int n){
	int i = 0, j = 0, k = 0;

	while (i < m && j < n)
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	while (i < m)
		c[k++] = a[i++];
	while (j < n)
		c[k++] = b[j++];
}

void print_array(char* title, int *key, int n_elem){
	int i;

	printf("\n %s:\n", title);
	for (i = 0; i < n_elem; ++i)
		printf("%4d", key[i]);
	putchar('\n');
}