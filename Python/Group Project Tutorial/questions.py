import json
import math


tutorialQuestions = {
        "question1": {
        "question": "___ front_door\n return open",
        "answer": "if",
        "description":" In order to open the door \n which keyword do you need to type in: if, of, not, too"
    },
        "question2": {
        "question": "___ opened_Office_Door\n return the door is open",
        "answer": "print",
         "description":" What keyword do we use to display text on the screen: \n print, Print, Printing, Prints "
    },
     "question3": {
        "question": "for comm __ commList",
        "answer": " in ",
         "description":" when using a FOR loop there's another keyword we need to include. \n which of the following do you need to put in:\n In, in, inn, inner. "
    },
     "question4": {
        "question": "__ exitDoor != 'exit':\n "'return You are still in the Warehouse.',
        "answer": "while",
         "description":" Which loop keyword should you use: While, while, whale"
    },
    "question5": {
        "question": "eight_squared = 8 __ 2",
        "answer": " ** ",
         "description":" You will need to use the Exponentiation operator "
    },

     "question6": {
        "question": "10 modulus 3 = 10 __ 3",
        "answer": " % ",
         "description":" You will need to use the Modulus operator"
    },
     "question7": {
        "question": "import math \n sqrt_of_49 = math.__(49)\n return " ,
        "answer": "sqrt",
         "description":" When using the math module you need to use a certain method to get the square root of a number. "
    },
     "question8": {
        "question": "items = __'gun, bullets, binoculars__'" ,
        "answer": "[]",
         "description":" A list is used to store multiple values in a single variable. "
    }
    

    

}

with open("tutorial.json", "w") as outfile:
    json.dump(tutorialQuestions, outfile)


tutorialParsed = json.loads(tutorialQuestions)

print(tutorialQuestions["question"])
