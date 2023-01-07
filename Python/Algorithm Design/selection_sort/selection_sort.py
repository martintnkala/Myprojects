import json


# 1. Name:
#      Martin Nkala
# 2. Assignment Name:
#      Lab 08: Sort
# 3. Assignment Description:
#      This is to check the algorithmic effeciency for the selection sort.
#       I have unsorted arrays and I need to sort them using a specific
#       algorithm.
# 4. What was the hardest part? Be as specific as possible.
#      I struggled to implement a for loop using a range. I was trying to translate 
#      how I do such a loop in Java. The other thing that was for me was where to 
#      place my asserts. 
# 5. How long did it take for you to complete the assignment?
#      3 hours

def get_data(file_number):
        file_names = ['Lab08.empty.json', 'Lab08.trivial.json', 
                      'Lab08.languages.json', 'Lab08.states.json', 'Lab08.cities.json']
        file_name = file_names[file_number -1]
        data_file = open(file_name, "r")
        data = json.load(data_file)
        return (data['array'],  file_name)
    
# This is a swap function.   
def swap (array, i_largest, i_pivot):
        temp_variable = array [i_largest]
        array [i_largest] = array [i_pivot]
        array [i_pivot] = temp_variable
                  
while True:
    
#   I created a menu just to make it easy to make a selection.
    print("----------------Menu-------------------------------")
    print(" 1. empty.json ")
    print(" 2. trivial.json ")
    print(" 3. languages.json ")
    print(" 4. states.json ")
    print(" 5. cities.json ")
    print("-----------------------------------------------")
        
    # Asking for user input for the file name.
    file_choice = int(input(" What is the name of the file? "))
    
    # Ensuring that the file choice is within range.
    assert file_choice > 0 and file_choice <= 5
    
    data, file_name = get_data(file_choice)
    # The data variable must be of list type.
    assert type(data) == list
    
    # This is the end of the Array.
    # This an outter loop that I am using to decrement my loop
    # from right to left. Each time I place the hightest value 
    # at the end of my array the last_idx pointer moves one 
    # step to the left until it equals 0.
    for last_idx in range(len(data)-1, 0, -1):
        largest_idx = 0    
        
        # This is my inner loop
        # I am using the search_idx to traverse my array from left to right.
        for search_idx in range(1, last_idx, +1):
            if  data[search_idx] > data[largest_idx]:
                assert search_idx >= 1 and largest_idx >= 0
                largest_idx = search_idx
             
            # I don't want to swap if the last_idx is greater than largest_idx.
            if data[last_idx] > data[largest_idx]:
                assert last_idx > 0 and  largest_idx >= 0 and largest_idx <= last_idx
                largest_idx = last_idx
            
            # Calling my swap method.
            swap(data,largest_idx,last_idx)
            
    print(f" The values in {file_name} are: ")
    
    # I am using this loop to print each element in the sorted array. 
    for element in range(0,len(data), +1): 
        assert element >= 0  and element <= len(data)
        print(data[element])      

        