import json
  
tutorialParsed = open('tutorial.json')
  

data = json.load(tutorialParsed)
  


print(data["question1"]["answer"])
tutorialParsed.close()