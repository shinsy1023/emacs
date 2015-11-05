import random

def sliding_puzzle():
	goal=[[1, 2, 3, 4],
	[5, 6, 7, 8],
	[9, 10, 11, 12],
	[13, 14, 15, 0]]
	(board, empty)=create_init_board()
	while True:
		print_board(board)
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
			if board[i][j]!=0:
				if j!=3:
					print(str(board[i][j]).rjust(2),end=' ')
				else:
					print(str(board[i][j]).rjust(2))
			else:
				if j!=3:
					print(' '.rjust(2),end=' ')
				else:
					print(' '.rjust(2))

def create_init_board():
	a=0
	b=3
	board1=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0]
	board=[[],[],[],[]]
	random.shuffle(board1)
	for i in range(4):	
		for j in range(4):
			board[i].append(board1[a])
			a+=1
	for i in range(4):
		for j in range(4):
			if board[i][j]==0:
				a=i
				b=j
				break
	return (board,(a,b))

def get_number():
	num=input("Type the number you want to move (Type 0 to quit): ")
	while not(num.isdigit() and 0<=int (num)<=15):
		num=input("Type the number you want to move (Type 0 to quit): ")
	return int(num)

def find_position(num, board):
	for i in range (4):
		for j in range(4):
			if board[i][j]==int(num):
				return (i, j)

def move(pos, opened, board):
	if pos[0]==opened[0]:
		if pos[1]==opened[1]+1 or pos[1]==opened[1]-1:
			board[opened[0]][opened[1]], board[pos[0]][pos[1]]\
			=board[pos[0]][pos[1]], board[opened[0]][opened[1]]
			return (pos, board)
	if pos[1]==opened[1]:
		if pos[0]==opened[0]+1 or pos[0]==opened[0]-1:
			board[opened[0]][opened[1]], board[pos[0]][pos[1]]\
			=board[pos[0]][pos[1]], board[opened[0]][opened[1]]
			return (pos, board)
	print("Can't move! Try again!")
	return (opened, board)