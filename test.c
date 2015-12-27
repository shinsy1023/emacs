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
  int i;
  int length=10;
  int a[10]={5,4,6,3,7,2,8,1,9,10};
  qsort(a, length, sizeof(a[0]),compare);
  for (i=0;i<10;i++){  
    printf("%d",a[i]);
  }
  return 0;
}
