#include <stdio.h>

int main(){
  int jun=0;
  int yun=0;
  int j_day=0;
  int y_day=0;
  int count=0;
  scanf("%d",&count);
  for (int j=0;j<count;j++){
    for (int i=0;i<7;i++){
      j_day=0;
      y_day=0;
      scanf("%d %d",&j_day, &y_day);
      jun=jun+j_day;
      yun=yun+y_day;
      printf("%d %d\n",jun,yun);
    }
    if (jun>yun){
      printf("God Junbeom bless you\n");
    }else if (yun>jun){
      printf("Cute Yunseong I love you\n");
    }else{
      printf("Seo A Jeong solo\n");
    }
    jun=0;
    yun=0;
  }
  return 0;
}
