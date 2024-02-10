"""Given a string s consisting of words and spaces, return the length of the last 
word in the string.

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6."""



s = input("Enter the string: ")

li=s.split()
print("The last word is ", li[-1], " with length ", len(li[-1]))