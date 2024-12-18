def reverse(word):
    # slicing Syntax: sequence [start:stop:step]
    return word[::-1]

def is_palindrome(word):
    reversed_name = reverse(word)
    return reversed_name == word

def main():
    return is_palindrome("kayak")

print(main())