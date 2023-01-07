from fileinput import close
import json

# 1. Name:
#      Martin Nkala
# 2. Assignment Name:
#      Lab 02: Authentication
# 3. Assignment Description:
#     The program is using to Array files which were converted from a json file.
#     The two arrays contain user names and password.
#     The objective is to make sure that the when the user types in both username and password both must match
#     based on the index position. For instance, username of index 0 must match the password on index 0.
#     if both values match the user is verified otherwise the user is not verified.
# 4. What was the hardest part? Be as specific as possible.
#      The hardest part for me was actually finding the right algorithm to make this program work.
#      The first solution I had didn't support dynamic program because it was only picking values on idnex 0 
#      from both arrays. I then finally thought of a better way to make it work which is the one I implemented.

#      The other problem I faced was that if the user was authenticated. I was get both results.
#      The many issue was on jumping out of the for loop.
# 5. How long did it take for you to complete the assignment?
#      4 hours
while True:
    try:
        authentication_file = open("Lab02.json", "r")
        dictionary_data = json.load(authentication_file)
        
        #Prompt user for input
        username_input = input("Enter username: ")
        user_password_input = input("Enter password: ")
        
        # Converted my dictionary into two arrays using the keys.
        username_list = dictionary_data['username']
        password_list = dictionary_data['password']
        
        # I am traversing each array once and 
        # then use the index to search for each value. 
        # In terms of time its O(n) and space is O(n)
        
        
        count = 0
        for i in range(len(username_list)):
            if username_input in username_list[i]:
                user_idx = i
            
        for j in range(len(password_list)):
            if user_password_input in password_list[j]:
                user_password_idx = j     
                if user_idx == user_password_idx:
                    count +=1
                    
        if count == 1:
            print("You are authenticated.")
        else: 
            print("You are not authorized to use the system.")  
                    

        authentication_file.close()
    except OSError:
        print("Can't be able to open the Lab02 file.")