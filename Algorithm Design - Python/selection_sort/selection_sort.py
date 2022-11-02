import json

def get_data(file_number):
        file_names = ['Lab08.cities.json', 'Lab08.empty.json', 
                      'Lab08.languages.json', 'Lab08.states.json', 'Lab08.trivial.json']
        file_name = file_names[file_number -1]
        data_file = open(file_name, "r")
        data = json.load(data_file)
        return (data['array'],  file_name)
    
def swap (array, i_largest, i_pivot):
        temp_variable = array [i_largest]
        array [i_largest] = array [i_pivot]
        array [i_pivot] = temp_variable
while True:
    
#   I created a menu just to make it easy to make a selection.
    print("----------------Menu-------------------------------")
    print(" 1. cities.json ")
    print(" 2. empty.json ")
    print(" 3. languages.json ")
    print(" 4. states.json ")
    print(" 5. trivial.json ")
    print("-----------------------------------------------")
        
    # Asking for user input for the file name.
    file_choice = int(input(" What is the name of the file? "))
    assert type(file_choice)
    
    # Ensuring that the file choice is within range.
    assert file_choice > 0 and file_choice <= 5
    
    data, file_name = get_data(file_choice)
    
    # The data variable must be of list type.
    assert type(data) == list
    
    # This is the end of the Array.
    for last_idx in range(len(data)-1, 0, -1):     
        largest_idx = 0
        # I am using this index set to 1 to traverse my Array.
        # from left to right.
        search_idx = 1

        for search_idx in range(search_idx, last_idx, +1):
            assert data[search_idx] > data[largest_idx]
            
            if  data[search_idx] > data[largest_idx]:
                largest_idx = search_idx
            
            swap(data,largest_idx,last_idx)
            
    print(f" The values in {file_name} are: ")
    for element in range(0,len(data), +1):
              
        print(data[element])      
    
        