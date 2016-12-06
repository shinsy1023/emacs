#include <stdio.h>
#include <stdlib.h>
#define LEFT 0
#define MIDDLE 1
#define RIGHT 2

#define DISC_COUNT 3

typedef struct _disc{
	int row;
	int column;
	int size;
}disc;


typedef struct _tower{
	int status[DISC_COUNT][DISC_COUNT];
	disc disc_list[DISC_COUNT];
}tower;

void move(tower* hanoi);

void print_tower_status(tower* hanoi){
	int i, j;
	for (i = 0; i < DISC_COUNT; i++){
		for (j = 0; j < DISC_COUNT; j++){
			if (hanoi->status[j][i] == 0){
				printf("0  ");
			}else{
				printf("%d  ", hanoi->status[j][i]);
			}
		}
		printf("\n");
	}
	printf("%s\n", "ㅡ ㅡ ㅡ");
}

void make_tower(tower* hanoi){
	int i, j;
	for (i = 0; i < DISC_COUNT; i++){
		hanoi->disc_list[i].row = i;
		hanoi->disc_list[i].column = 0;
		hanoi->disc_list[i].size = i+1;
		hanoi->status[0][i] = i+1;
	}
	for (i = 1; i < DISC_COUNT; i++){
		for (j = 0; j < DISC_COUNT; j++){
			hanoi->status[i][j] = 0;
		}
	}
}

int main(void){
	tower* hanoi = (tower*)malloc(sizeof(tower));
	make_tower(hanoi);
	print_tower_status(hanoi);
	return 0;
}
