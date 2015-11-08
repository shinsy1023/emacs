#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b){
  if(*(int*)a<*(int*)b){
    return -1;
  }else if (*(int*)a ==*(int*)b){
    return 0;
  }
  return 1;
}

int main(){
  int count, i, j;
  int length[500]={0};
  int array[500]={0};
  int price=0;
  scanf("%d", &count);
  for (i=0;i<count;i++){
    scanf("%d", &length[i]);
  }
  for (i=0; i<count; i++){
    for (j=0; j<length[i]; j++){
      scanf("%d", &array[j]);
    }
    for (j=0; j<length[i]-1;j++){
      qsort(array, length[i], sizeof(int),compare);
      price=array[j]+array[j+1]+price;
      array[j+1]=array[j+1]+array[j];
      array[j]=0;
    }
    printf("%d\n", price);
    price=0;
  }
  return 0;
}
