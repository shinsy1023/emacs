#include <stdio.h>
#include <stdlib.h>
 
int main(void){
        int t, i, j;
        int **result, cnum, temp;
        result = (int**)malloc(sizeof(int)*t);
        for(i = 0; i < t; i++){
                result[i] = (int*)malloc(sizeof(int)*2);
                result[i] = [[0],[0]];
        }
        scanf("%d",&t);
        for(i = 0; i < t; i++){
                scanf("%d",&cnum);
                for(j = 0; j < cnum;j++){
                        scanf("%d", &temp);
                        if(temp%2 == 0){
                                result[i][0] += temp;
                        }
                        else {
                                result[i][1] += temp;
                        }
                }
        }
        for(i = 0;i < t; i++){
                printf("%d %d\n",result[i][0],result[i][1]);
        }

    }
