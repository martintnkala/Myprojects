# 1. Name: 
#    Martin Nkala
# 2. Assignment Name: 
#    Lab 01: Python Review
# 3. Assignment Description:
#    This is a number guessing game. It will prompt a user to enter guess a number until the guess matches the randomly generated number.
# 4. What was the hardest part? Be as specific as possible. 
# There was honestly nothing hard, I was able to complete it without any hurdles.
#  This assignement really helped improve my thought process. 
#  Before I did some coding I made sure that I understood what the problem needs me to do.
# I wrote down what I understood. I then wrote down all the things I would need to accomplish it such as variables, a list, loop etc.
# 5. How long did it take for you to complete the assignment?
#    2 hours  

import random

# Game introduction
print('\nThis is the "guess a number" game.\nYou try to guess a random number in the smallest number of attempts.\n\n')

# Prompt the user for how difficult the game will be. Ask for an integer


gamedifficultScale = int(input("One a scale from '1 - 5'. How difficult do you think the game will be? "))

# Generate a random number between 1 and the chosen value(value_max)
value_max = 100
value_random = random.randint(1, value_max)
guessList = []
userInput = 1
count = 0

print("Guess a number between 1 and 100.\n")
while userInput != value_random:
    userInput = int(input("Pick a positive integer: "))
    count += 1
    guessList.append(userInput)
    
    if userInput > value_random:
        print(f"{userInput}, Too high!")
    if userInput < value_random:
        print(f"{userInput}, Too low")
    if userInput == value_random:
        exit # Will jump out of the while Loop once user input matches the random number.
print(f"You were able to find the number in {count} guesses.")
print(f"The numbers you guessed were: {guessList}") # This will give me an array of all the guesses I made.


