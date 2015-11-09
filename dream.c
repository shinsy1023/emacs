#include <stdio.h>
#include <stdlib.h>

int main(){
	int count, i, j;
	int* width;
	int* height;
	scanf ("%d", &count);
	width=(int*)malloc(sizeof(int*)*count);
	height=(int*)malloc(sizeof(int*)*count);
	for (i=0; i<count; i++){
		scanf("%d", width[i]);
	}
	for (i=0; i<count; i++){
		scanf("%d", height[i]);
	}
	return 0;
}