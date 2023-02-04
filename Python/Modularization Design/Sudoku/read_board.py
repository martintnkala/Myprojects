# 1. Name:
#      Martin Nkala
# 2. Assignment Name:
#      Lab 05 : Sudoku Draft
# 3. Assignment Description:
#      Checking to see if the row, colum, and the three by 
#      three grid contains unique numbers.
# 4. What was the hardest part? Be as specific as possible.
#      Reading the Json file, getting the 
#      columns within the row.
# 5. How long did it take for you to complete the assignment?
#      6 hours.


import json

def display_board(board):
    print("    A B C   D E F   G H I")
    for row in range(len(board)):
        print(f"{row+1}   ", end= "")
        for col in range(len(board[row])):
            if col % 3 == 0 and col != 0:
                print("|", end=" ")
            if board[row][col] == 0:
                print(" ", end= " ")
                
            else:
                print(board[row][col], end= " ")
        if row in [2, 5]:
            print("\n    ------+-------+------", end="")
        print("\n", end= "")


def read_board(board):
    while True:
            
        file_name = input("Where is your board located? ")
        try:
            
            file = open(file_name, "r")
            board = json.load(file)
            
            board = board['board']
            
                
            return board
            
        except OSError:
            print("The board couldn't be found.")
            file.close()
            
        
                    
def is_valid(square, board):
    
    convert_letter_to_num = {"A": 1, "B": 2, "C": 3, "D": 4, "E": 5, "F": 6, "G": 7, "H": 8, "I": 9}
    col = convert_letter_to_num[square[0]] -1
    
    row = int(square[1]) -1
    
    if board[row][col] == 0:
        board[row][col] = " "
        
    if board[row][col] == " ":
        return True, (row, col)
    
    else:
        print(f"Error {square} is already filled. ")
        return False, (row, col)
    

def checking_for_rules(row_col, number_input, board):
    
    # checking for the row and column
    for row in board[row_col[0]]:
        if number_input == row:
            return False
    for row in board:
        col_number = row[row_col[1]]
        if number_input == col_number:
            return False
        
    # Creating sets for rows.  
    if row_col[0] <= 2:
        row_set = [0, 1, 2]
    elif row_col[0] <= 5:
        row_set = [3, 4, 5]
    else:
        row_set = [6, 7, 8]
        
        
    # Creating sets for columns.  
    if row_col[1] <= 2:
        col_set = [0, 1, 2]
    elif row_col[1] <= 5:
        col_set = [3, 4, 5]
    else:
        col_set = [6, 7, 8]
        
    for row in row_set:
        for col in col_set:
            if number_input == board[row][col]:
                return False
            
    return True
    
def get_input(board):
    valid = False
    
    while not valid:
        
        print("Specify a coordinate to edit or 'Q' to save and quit ")
        square = input("> ").upper()
        
        if len(square) > 2:
            print("Invalid input! It must have a length of two characters.")
            
        if square == 'Q':
            save_file(board)
            print("Save the game. ")
            return True
        elif square[0].isdigit() and not square[1].isdigit():
            square = square[1] + square[0]
        
        if square[0] > "I" or square[0] < "A":
            print(" Invalid character input. ")
            
        elif int(square[1]) > 9 or int(square[1]) < 1:
            print("Invalid number input. ")
            
        else:
            valid, row_col = is_valid(square, board)
    valid = False
    
    while not valid:
        # Inserting a number into a square.
        number_input = input(f"What number goes in {square}? ").upper()
        
        # If q or Q is pressed the current board gets saved.
        if number_input == "Q":
            save_file(board)
            print("Save the game.")
            return True
        
        # checking for number range and making sure that  
        # the rules for playing the game are being followed.
        elif number_input.isdigit():
            if int(number_input) >= 1 and int(number_input) <= 9:
                valid = checking_for_rules(row_col, number_input, board)
            if valid == True:
                board[row_col[0]][row_col[1]] = number_input
                display_board(board)
    return False
def save_file(board):
        save_to_file = input(f"What's the new file name? ")
        
        save = open(save_to_file, "w")
        board = {"board": board}
        board = json.dump(board, save)

        save.close()
    
board = read_board("board")
display_board(board)

play_game = False
while not play_game:
    get_input(board)