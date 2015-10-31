#include <stdio.h>

int main(){
  int jun=0;
  int yun=0;
  int j_day=0;
  int y_day=0;
  for (int i=0;i<7;i++){
    j_day=0;
    y_day=0;
    scanf("%d %d",&j_day, &y_day);
    jun=jun+j_day;
    yun=yun+y_day;
  }
  if (jun>yun){
    printf("God junbeom bless you");
  }else if (yun>jun){
    printf("Cute Yunseong I love you");
  }else{
    printf("Seo A Jeong solo");
  }
  return 0;
}
