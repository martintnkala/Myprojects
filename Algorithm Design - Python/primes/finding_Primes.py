import math

while True:
    # This Array will a range of numbers
    # based on the user input.
    primes = []

    # Prompt for user input
    user_input = int(input("Enter a number: "))

    # Creating a range of numbers based on 
    # user input and then inserting them in a list.
    for number in range(1, user_input):
        number+=1
        primes.append(number)
    
    # Finding the square root of the user input
    # and then stop at iterating once I find the that
    # square root because, I would have find all nonprimes.
    for num_idx in range(int((math.sqrt(user_input)))):
        
            # Value is each number in my list 
            # based on the index position.
            num_value = primes[num_idx]

            if num_value != 0:
                
                # I am finding all even numbers 
                # and then assign them a zero.
                start_idx = num_idx + num_value
                
                for idx in range(start_idx, len(primes), num_value):
                    primes[idx] = 0
    
    # primes = filter(lambda unwanted_num: unwanted_num != 0, primes)
      
    # print(list(primes)) 
                         
    for value in primes:
        
        if value != 0:
            print(value, end = " ")
    print()       
        
        