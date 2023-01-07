
import json

# 1. Name:
#      Martin Nkala
# 2. Assignment Name: Advanced Search.
#      Lab 06: Advanced Search
# 3. Assignment Description:
#      This program performs a search within an array using user provided word.
#      if the word exists i will show that the message has been found otherwise
#      I will say the word doesn't exists. The main focus is to use the most 
#      efficient algorithm to this. 
# 4. Algorithmic Efficiency
#      0 (log n). I was cutting my array into half until I find the word 
#      I am looking for. Although I have a while loop. I drop all constants
#      and non-dominants.
# 5. What was the hardest part? Be as specific as possible.
#      At first I wanted to do everything at once and that really got me confused.
#      I made a couple of drafts before finally deciding on having it look like this.
# 6. How long did it take for you to complete the assignment?
#       4 hours



# Created a function for getting the data from each file.
# I put my 4 files in a list so that I can access each 
# using the index value. That is why I am substrating 1
# so that the I get the correct index.
while True:
    def get_data(file_number):
        file_names = ['Lab06.countries.json', 'Lab06.empty.json', 'Lab06.languages.json', 'Lab06.trivial.json']
        file_name = file_names[file_number -1]
        data_file = open(file_name, "r")
        data = json.load(data_file)
        return data['array']
    
#   I created a menu just to make it easy to make a selection.
    print("----------------Menu-------------------------------")
    print(" 1. countries.json ")
    print(" 2. empty.json ")
    print(" 3. languages.json ")
    print(" 4. trivial.json ")
    print("-----------------------------------------------")
        
    # Asking for user input for the file name and word we are searching for.
    file_choice = int(input(" What is the name of the file? "))
    word_choice = input(" What name are we looking for? ")
    data = get_data(file_choice)
    # print(data)

    # Created a function just for searchin for the word.
    # It takes two parameters and both parameters matches
    # the user input and the chosen file.
    def word_search(word_search, data_to_search):

    # Created my variables for the start pointer and end pointer in an array.
        start_idx = 0
        end_idx = len(data_to_search) - 1
        
        found = False
        
        while found == False:
    # Since my elements are sorted. Small to bif elements
    # is from left to right. If my left pointer (start_idx) becomes greater.
    # I know that I have traversed the array and the word wasn't found.
            if start_idx > end_idx:
                return " Word doesn't exists."
            
    # This is repeatable that's why I created this middle pointer within a loop.
            middle_point = (start_idx + end_idx) // 2
    
    # This a my base case. If the word I am looking for is at the middle        
            if data_to_search[middle_point] == word_search:
                return " Word exists."
            
            if data_to_search[middle_point] < word_search:
                start_idx = middle_point + 1
                
            if data_to_search[middle_point] > word_search:
                end_idx = middle_point - 1
                
    result = word_search(word_choice, data)
    print(result)