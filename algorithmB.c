#include <stdio.h>
#include <stdlib.h>

int main(){
  int count=0;
  int* height=(int*)malloc(sizeof(int));
  long long** pascal;
  int i, j, k;
  scanf("%d",&count);
  pascal=(long long**)malloc(sizeof(long long*));
  for (i=0;i<count;i++){
    scanf("%d",&height[i]);
  }
  printf("%lld",pascal[0][0]);
  for (i=0;i<count;i++){
    for(j=0;j<height[i];j++){
      pascal[j]=(long long*)malloc(sizeof(long long)*j);
      pascal[j][0]=1;
      pascal[j][j]=1;
      printf("good\n");
      printf("%lld ",pascal[j][0]);
      if (j>0){
  	for (k=1;k<j+1;k++){
  	  pascal[j][k]=pascal[j][k-1]+pascal[j-1][k];
  	  printf("%lld ",pascal[j][k]);
  	}
      }
      printf("%lld",pascal[j][j]);
    }
    pascal=NULL;
  }
  return 0;
}
