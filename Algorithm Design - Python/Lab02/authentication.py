import json

try:
    # _username = input(str(" Enter name: "))
    # _password = input(str(" Enter password: "))
    authentication_file = open("Lab02/Lab02.json", "r")
    dictionary_data = json.load(authentication_file)
    
    print(type(dictionary_data)) # Checking if the type is dict.
    """ my time complexity is O(1) and my space complexity is O(1) too.
    I am traversing the dictionary using the keys which are username and password.
    doing this doesn't call for additional space.
    
    """
    for i in dictionary_data ['username']:
        print(i)
    # user_passwords = dictionary_data['password']
    # for i in user_names:
        
    #     print(int(user_names[i]))
    
    # if _username == user_name and _password == user_password:
    #     print("User authenticated.")
    # elif _username == user_name and _password != user_password:
    #     print("User password incorrect")
    # elif _username != user_name and _password == user_password:
    #     print("User name incorrect")
    # else:
    #     print("User name and password incorrect")
    authentication_file.close()

except OSError:
    print("Unable to open the file Lab02.json")