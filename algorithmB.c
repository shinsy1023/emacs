#include <stdio.h>
#include <stdlib.h>

int main(){
  int count=0;
  int* height;
  long long** pascal;
  int i, j, k;
  scanf("%d",&count);
  height=(int*)malloc(sizeof(int)*count);
  for (i=0;i<count;i++){
    scanf("%d",&height[i]);
  }
  for (i=0;i<count;i++){
    pascal=(long long**)malloc(sizeof(long long**)*height[i]+1);
    for(j=0;j<height[i];j++){
      pascal[j]=(long long*)malloc(sizeof(long long*)*j+1);
      pascal[j][0]=1;
      pascal[j][j]=1;
      if(j!=0){
      printf("%lld ",pascal[j][0]);
      }
      if (j>0){
  	for (k=1;k<j;k++){
  	  pascal[j][k]=pascal[j-1][k-1]+pascal[j-1][k];
  	  printf("%lld ",pascal[j][k]);
  	}
      }
      printf("%lld\n",pascal[j][j]);
    }
    free(pascal);
  }
  return 0;
}
