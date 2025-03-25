#Python Program to Tokenize a Given String Using Spaces as Delimiters

s = input()
tokens = s.split()
for token in tokens:
    print(token)


#Python Program to Check if a Given String is a Valid Variable Name in Python
import keyword

def is_valid_python_var(s):
    return s.isidentifier() and not keyword.iskeyword(s)

s = input()
print("Valid" if is_valid_python_var(s) else "Invalid")

