import math

while True:
    # This Array will a range of numbers
    # based on the user input.
    numbers = []
    primes = []

    # Prompt for user input
    user_input = int(input("Enter a number: "))
    

    # Creating a range of numbers based on 
    # user input and then inserting them in a list.
    for number in range(1, user_input):
            
        number+=1
        assert type(numbers) == list
        numbers.append(number)
        
    # Finding the square root of the user input
    # and then stop at iterating once I find the that
    # square root because, I would have find all nonprimes.
    for num_idx in range(int((math.sqrt(user_input)))):
        
            # Value is each number in my list 
            # based on the index position.
            num_value = numbers[num_idx]
                        
            if num_value != 0:
                
                # I am finding all even numbers 
                # and then assign them a zero.
                start_idx = num_idx + num_value
                assert start_idx >= 2
                
                for idx in range(start_idx, len(numbers), num_value):
                    numbers[idx] = 0
            
                    
    # iterating through the primes list.                    
    for value in numbers:
        
        # filtering all values that i assigned to zero
        # since they are not primes.
        if value != 0:
            
            # Adding all prime numbers in a new list.
            assert type(primes) == list
            primes.append(value)
            
    # print the new list that contains all prime numbers.       
    print(f"This program will find all the prime numbers at or below N. Select that N: {user_input}")
    
    print(f"The prime numbers at or below {user_input} are {primes}.")
         
        
        