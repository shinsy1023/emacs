import random
class SlidingBoard(object):
    def __init__(self):
        a=0
        board1=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0]
        self.board=[[],[],[],[]]
        random.shuffle(board1)
        for i in range(4):	
            for j in range(4):
                self.board[i].append(board1[a])
                a+=1
        for i in range(4):
            for j in range(4):
                if self.board[i][j]==0:
                    self.empty=(i,j)

    def move(self, num):
        self.pos=self.__find_position(num)
        if self.pos[0]==self.empty[0]:
            if self.pos[1]==self.empty[1]+1 or self.pos[1]==self.empty[1]-1:
                self.board[self.empty[0]][self.empty[1]], self.board[self.pos[0]][self.pos[1]]\
                =self.board[self.pos[0]][self.pos[1]], self.board[self.empty[0]][self.empty[1]]
                self.empty=self.pos
        if self.pos[1]==self.empty[1]:
            if self.pos[0]==self.empty[0]+1 or self.pos[0]==self.empty[0]-1:
                board[self.empty[0]][self.empty[1]], board[self.pos[0]][self.pos[1]]\
                =board[self.pos[0]][self.pos[1]], board[self.empty[0]][self.empty[1]]
                self.empty=self.pos
        print("Can't move! Try again.")
        
    def __find_position(self, num):
        for i in range (4):
            for j in range(4):
                if self.board[i][j]==int(num):
                    return (i, j)

    def print_board(self):
        print("S|  1  2  3  4\n-+-----------")
        for i in range (4):
            print(str(i+1)+" |",end=' ')
            for j in range(4):
                if self.board[i][j]!=0:
                    if j!=3:
                        print(str(self.board[i][j]).rjust(2),end=' ')
                    else:
                        print(str(self.board[i][j]).rjust(2))
                else:
                    if j!=3:
                        print(' '.rjust(2),end=' ')
                    else:
                        print(' '.rjust(2))

def get_number():
    num=input("Type the number you want to move (Type 0 to quit): ")
    while not (num.isdigit() and 0<=int(num)<=15):
        num=input("Type the number you want to move (Type 0 to quit): ")
    return int(num)

#GOAL=[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,0]]
#slider=SlidingBoard()
#while True:
#    slider.print_board()
#    if slider.board==GOAL:
#        print("Congratulations!")
#        break
#    num=get_number()
#    if num==0:
#        break
#    slider.move(num)
#print("Please come again")
