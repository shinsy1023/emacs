#include <stdio.h>
#include <stdlib.h>

int main(){
  int count, big;
  int** list;
  int i, j, k, half;
  scanf("%d",&count);
  list=(int**)malloc(sizeof(int**)*count);
  for (i=0;i<count;i++){
    list[i]=(int*)malloc(sizeof(int*)*(i+1));
    for (j=0;j<i+1;j++){
      scanf("%d",&list[i][j]);
    }
  }
  for(i=0;i<count;i++){
    big=0;
    half=(i+1)/2;
    for (j=0;j<i+1;j++){
      for (k=0;k<i+1;k++){
	if (list[i][j]<list[i][k]){
	  big++;
	}else if (list[i][j]==list[i][k]){
	  big--;
	}
      }
      if (big==half){
	printf("%d",list[i][j]);
	break;
      }
      big=0;
    }
    printf("\n");
  }
  return 0;
}
