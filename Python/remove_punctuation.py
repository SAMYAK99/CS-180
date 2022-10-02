#Python program to remove punctuations from a string

#This program removes all punctuations from a string. We will check each character of the string using for loop.
#If the character is a punctuation, empty string is assigned to it.

# define punctuation
punctuations = r'''!()-[]{};:'"\,<>./?@#$%^&*_~'''

my_str = "Hello!!!, he said ---and went."

# To take input from the user
my_str = input("Enter a string: ")

# remove punctuation from the string
no_punct = ""
for char in my_str:
   if char not in punctuations:
       no_punct = no_punct + char

# display the unpunctuated string
print(no_punct)
