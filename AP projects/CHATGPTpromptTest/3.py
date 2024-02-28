# write a python program that gets a string of numbers using the simple input() function without writting any message at the terminal and then seperates the digits of the string of numbers given and turns them into integer like n then print the following : "n" + ":  " + "n" * n

# Get input as a string
input_string = input()

# Iterate over each character in the input string
for char in input_string:
    # Convert the character to an integer
    n = int(char)
    # Print the desired output format
    print(f"{n}: {''.join([str(n)] * n)}")
