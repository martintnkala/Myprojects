while True:
    
    def display_francois():
        # I am prompting for user input.
        user_input = input(" Which Francois number would you like to see? ")
        
        assert type(user_input) == int
        assert user_input >= 1
        # I am calling the compute_francios function
        # passing the user input as an argument.
        print(f"Francois number {user_input} is {compute_francios(user_input)}")
    
    # I am passing the input_number variable as a parameter.
    def compute_francios(input_number):
        
        # This is my base case. if the input is either 
        #  1 or 2. I will return that number.
        if input_number == 2 or input_number == 1:
            return input_number
    
        if input_number < 1:
            return " out of range."
        
        #  I am initializing my variables with
        #  its proper value.
        first_position = 2
        second_position = 1
        current_position = 3
        
        for number in range(3, input_number, 1):
            assert number >= 3
            
            # I am reasigning my variables by moving my pointers.
            first_position = second_position
            second_position = current_position
            current_position = first_position + second_position
            
        return current_position
    
    # I am calling this function so that my code can start 
    #  asking for user input and then calculate the francios 
    # based on the user input
    display_francois()