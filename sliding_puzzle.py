import random

def sliding_puzzle():
	goal=[[1, 2, 3, 4],
	[5, 6, 7, 8],
	[9, 10, 11, 12],
	[13, 14, 15, '']]
	(board, empty)=create_init_board()
	while True:
		print_board(board)
		print("Type the number you want to move (Type 0 to quit): ")
		if board==goal:
			printf("Congratulations!")
			break
		num=get_number()
		if num==0:
			break
		pos=find_position(num, board)
		(empty, board)=move(pos, empty, board)
	print("Please com again.")

def print_board(board):
	print("S| 0  1  2  3\n-+-----------")
	for i in range (4):
		print(str(i)+"|",end='')
		for j in range(4):
			print(str(board[i][j]).rjust(2),end=' ')
		print()

def trans(board):
	board1=[[],[],[],[]]
	for i in range(4):
		for j in range(4):
			board1[i].append(board[j][i])
			print(board1)
	return board1
def create_init_board():
	a=3
	b=0
	board=[[1, 2, 3, 4],[5, 6, 7, 8],[9, 10, 11, 12],[13, 14, 15, 0]]
	for i in range(2):	
		for i in range(4):
			random.shuffle(board[i])
			a=(board[3].index(0))
		board=trans(board)
		b=(board[a].index(0))
	board=trans(board)
	print(b,a, board)
	return (board,(b,a))

#def get_number():
        

sliding_puzzle()
