# 1. Name:
#      Martin Nkala
# 2. Assignment Name:
#      Lab 01: Tic-Tac-Toe
# 3. Assignment Description:
#      Play the game of Tic-Tac-Toe
# 4. What was the hardest part? Be as specific as possible.
#      figuring out how to place each logic in the correct function.
#      I needed first to understand how this game was played
#      inorder for me to be able to start working on it.
# 5. How long did it take for you to complete the assignment?
#      5hours

import json
import random

# The characters used in the Tic-Tac-Too board.
# These are constants and therefore should never have to change.
X = 'X'
O = 'O'
BLANK = ' '

# A blank Tic-Tac-Toe board. We should not need to change this board;
# it is only used to reset the board to blank. This should be the format
# of the code in the JSON file.
blank_board = {  
            "board": [
                BLANK, BLANK, BLANK,
                BLANK, BLANK, BLANK,
                BLANK, BLANK, BLANK ]
        }

def read_board(filename):
    '''Read the previously existing board from the file if it exists.'''
    try:
        file = open("board.json")
        data = json.load(file)
        file.close()
        return data['board']
    except:
        return blank_board['board']
        
    # Put file reading code here.
    return blank_board['board']

def save_board(filename, board):
    '''Save the current game to a file.'''
    dict = {"board": board}
    with open(filename, "w") as file:
        json.dump(dict, file)
    # Put file writing code here.

def display_board(board):
    '''Display a Tic-Tac-Toe board on the screen in a user-friendly way.'''
    print(board[0] + " | " + board[1] + " | " + board[2])
    print("--+---+--")
    print(board[3] + " | " + board[4] + " | " + board[5])
    print("--+---+--")
    print(board[6] + " | " + board[7] + " | " + board[8])
    # Put display code here.

def is_x_turn(board):
    '''Determine whose turn it is.'''
    count_x = 0
    count_o = 0
    
    for spot in board:
        if spot == "X":
            count_x +=1
        elif spot == "O":
            count_o +=1
    
    if count_x > count_o:
        return False
    
    return True

def play_game(board):
    '''Play the game of Tic-Tac-Toe.'''
    while True:
        display_board(board)
        if is_x_turn(board):
            user_input = input ("X> ")
        else:
            user_input = input ("O> ")
            
        if user_input == "q":
            save_board("board.json", board)
            quit()
            
        user_inp = int(user_input) 
            
        if board[user_inp-1] == " ":
            if is_x_turn(board):
                board[user_inp-1] = "X"
            else:
                board[user_inp-1] = "O"
                
        else:
            print("Spot already taken.")
    
        if game_done(board, message=True):
            open('board.json', 'w').close()
            quit()
    # Put game play code here. Return False when the user has indicated they are done.
    return False

def game_done(board, message=False):
    '''Determine if the game is finished.
       Note that this function is provided as-is.
       You do not need to edit it in any way.
       If message == True, then we display a message to the user.
       Otherwise, no message is displayed. '''

    # Game is finished if someone has completed a row.
    for row in range(3):
        if board[row * 3] != BLANK and board[row * 3] == board[row * 3 + 1] == board[row * 3 + 2]:
            if message:
                print("The game was won by", board[row * 3])
            return True

    # Game is finished if someone has completed a column.
    for col in range(3):
        if board[col] != BLANK and board[col] == board[3 + col] == board[6 + col]:
            if message:
                print("The game was won by", board[col])
            return True

    # Game is finished if someone has a diagonal.
    if board[4] != BLANK and (board[0] == board[4] == board[8] or
                              board[2] == board[4] == board[6]):
        if message:
            print("The game was won by", board[4])
        return True

    # Game is finished if all the squares are filled.
    tie = True
    for square in board:
        if square == BLANK:
            tie = False
    if tie:
        if message:
            print("The game is a tie!")
        return True


    return False

# These user-instructions are provided and do not need to be changed.
print("Enter 'q' to suspend your game. Otherwise, enter a number from 1 to 9")
print("where the following numbers correspond to the locations on the grid:")
print(" 1 | 2 | 3 ")
print("---+---+---")
print(" 4 | 5 | 6 ")
print("---+---+---")
print(" 7 | 8 | 9 \n")
print("The current board is:")
board = read_board("data")
play_game(board)
# The file read code, game loop code, and file close code goes here.
