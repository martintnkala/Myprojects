import json
import math


tutorialQuestions = {
        "question1": {
        "question": "___ front_door",
        "answer": "if",
        "description":" "
    },
        "question2": {
        "question": "___ opened_Office_Door",
        "answer": "print"
    },
     "question3": {
        "question": "for comm __ commList",
        "answer": "in"
    },
     "question4": {
        "question": "__ exitDoor != 'exit':\n "'return You are still in the Warehouse.',
        "answer": "while"
    },
    "question5": {
        "question": "eight_squared = 8 __ 2",
        "answer": " ** "
    },

     "question6": {
        "question": "10 modulus 3 = 10 __ 3",
        "answer": " % "
    },
     "question7": {
        "question": "import math \n sqrt_of_49 = math.__(49)" ,
        "answer": "sqrt"
    },
     "question8": {
        "question": "fifteen_floordiv_nine = 15 __ 9" ,
        "answer": "//"
    }
    

    

}

with open("tutorial.json", "w") as outfile:
    json.dump(tutorialQuestions, outfile)


tutorialParsed = json.loads(tutorialQuestions)

print(tutorialQuestions["question"])
