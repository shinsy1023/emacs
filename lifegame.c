#include <stdio.h>

int checknum(int x, int y) {

}

int main() {
	int board[11][11] = {0}, board2[11][11];
	int i, j, num;
	int x0, x2, y0, y2;
	int dead = 0;

	board[5][5] = 1;
	board[5][4] = 1;
	board[5][6] = 1;
	board[4][5] = 1;
	board[6][5] = 1;

	for (i=0; i<11; i++) 
		for (j=0; j<11; j++)
		board2[i][j] = board[i][j];
	do {
		system("clear");	

		for (i=0; i<11; i++) {
			for (j=0; j<11; j++) 
				printf("%d ", board[i][j]);
			printf("\n");
		}
		
		for (i=0; i<11; i++) {
			for (j=0; j<11; j++) {
				
				x0 = (i == 0) ? 10 : i-1;
				x2 = (i == 10) ? 0 : i+1;

				y0 = (j == 0) ? 10 : j-1;
				y2 = (j == 10) ? 0 : j+1;
				
				num = board[x0][y0] + board[i][y0] + board[x2][y0] 
					+ board[x0][j] + board[x2][j] 
					+ board[x0][y2] + board[i][y2] + board[x2][y2];

				dead = (dead == 1 || num == 3) ? 1 : 0;

				if(num == 2) {
					if (board[i][j] == 1) {
						board2[i][j] = 1;
						dead = 1;
					}
				}
				else if(num == 3)
					board2[i][j] = 1;
				else 
					board2[i][j] = 0;
			}
		}
	getchar();

	for (i=0; i<11; i++) 
		for (j=0; j<11; j++)
		board[i][j] = board2[i][j];
	} while(dead);
}