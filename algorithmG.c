#include <stdio.h>
#include <stdlib.h>

int main(){
  int count, big;
  int* list;
  int i, j, k, half;
  scanf("%d",&count);
  for (i=0;i<count;i++){
    big=0;
    half=(i+1)/2;
    list=(int*)malloc(sizeof(int*)*(i+1));
    for (j=0;j<i+1;j++){
      scanf("%d",&list[j]);
    }
    for (j=0;j<i+1;j++){
      for (k=0;k<i+1;k++){
	if (list[j]<list[k]){
	  big++;
	}
      }
      printf("%d %d\n",big, half);
      if (big==half){
	printf("%d",list[j]);
	break;
      }
      big=0;
    }
    printf("\n");
  }
  return 0;
}
