#include <stdio.h>
#include <stdlib.h>

int main(){
  int count;
  int* length;
  int* array;
  int i, j, odd, even;
  scanf("%d",&count);
  length=(int*)malloc(sizeof(int*)*count);
  for(i=0;i<count;i++){
    odd=0;
    even=0;
    scanf("%d",&length[i]);
    array=(int*)malloc(sizeof(int*)*length[i]);
    for (j=0;j<length[i];j++){
      scanf("%d",&array[j]);
      if (array[j]%2==0){
	even=even+array[j];
      }else{
	odd=odd+array[j];
      }
    }
    printf("%d %d\n",even, odd);
  }
  return 0;
}
