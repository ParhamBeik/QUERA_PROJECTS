# write a python program that gets an integer as input using the simple input() function without writting any message at the terminal that given the following inputs , prints out the outputs :

# input : 3
# output : 
# {}
# {1}
# {1, 2}
# {1, 2, 3}
# {1, 3}
# {2}
# {2, 3}
# {3}

# input : 1 
# output : 
# {}
# {1}

# -show an empty set as "{}" and not as "set()"
# -store all the subsets and sort the elements inside of the subsets and view the elements in the subsets as words and print them by alphabetic orders

def extract_https(input_text):
    words = input_text.split()
    https_words = [word for word in words if 'https' in word.lower()]
    return ' '.join(https_words)

input_text = "HTTPS is short form of Hyper text transfrd protocol secure.It doesn't mean you can trust all https sites !!!!! It only means data has been encrypted before transfer."
output = extract_https(input_text)
print(output)

