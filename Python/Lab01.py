# 1. Name: 
#    -your name-
# 2. Assignment Name: 
#    Lab 01: Python Review
# 3. Assignment Description:
#    -describe what this program is meant to do-
# 4. What was the hardest part? Be as specific as possible.
#    -a paragraph or two about how the assignment went for you-
# 5. How long did it take for you to complete the assignment?
#    -total time in hours including reading the assignment and submitting the program-  

import random

# Game introduction
print('\nThis is the "guess a number" game.\nYou try to guess a random number in the smallest number of attempts.\n\n')

# Prompt the user for how difficult the game will be. Ask for an integer

print("One a scale from '1-5'. How difficult do you think the game will be?\n")

gamedifficultScale = int(input("Enter a number: "))

# Generate a random number between 1 and the chosen value
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
        print("Too high!")
    if userInput < value_random:
        print("Too low")
    if userInput == value_random:
        exit
print(f"You were able to find the number in {count} guesses.")
print(f"The numbers you guessed were: {guessList}")

# Give the user instructions as to what he or she will be doing

# Initialize the sentinal and the array of guesses

# Play the guessing game

    # Prompt the user for a number

    # Store the number in an array so it can be displayed later

    # Make a decision: was the guess too high, too low, or just right

# Give the user a report: How many guesses and what the guesses where
