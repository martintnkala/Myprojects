import json

try:
    authentication_file = open("Lab02/Lab02.json", "r")
    
    dictionary_data = json.load(authentication_file)
    
    for i in dictionary_data['username']:
        print(i)
    
    
    
    authentication_file.close()

except OSError:
    print("Unable to open the file Lab02.json")