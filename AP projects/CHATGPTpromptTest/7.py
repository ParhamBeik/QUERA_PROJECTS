# write a python program that  does the following tasks in order : 
# 1. get input using input() function without writing anything in the terminal
# 2. removes all the characters except space and words from 'a' to 'z' and from 'A' to 'Z'
# 3. creates a empty vector , named words , of strings that stores each word seperated in the text by space
# 4. make a vector called vowels and initialize it with the following characters : {'a' ,'e', 'o' , 'u' , 'i' ,'y' } 
# 5.  checks each element in the words vector so that there would be no elements with 5 or more consecutive characters not in the vowels vector and if there were 5 or more consecutive characters which were not in the vowels vector , add the word , containing the characters , to a vector named resault 
# 6. if the ascii value of all the characters in the element of the resault vector were not between 96 and 122 then remove that element from the vector and print the rest of the elements with a space between them

import re

# Task 1: Get input from the user
text = input()

# Task 2: Remove all characters except space and words from 'a' to 'z' and from 'A' to 'Z'
text = re.sub(r'[^a-zA-Z\s]', '', text)

# Task 3: Create a vector of strings storing each word separated by space
words = text.split()

# Task 4: Initialize a vector called vowels
vowels = {'a', 'e', 'o', 'u', 'i', 'y'}

# Task 5: Check for words with 5 or more consecutive characters not in the vowels vector
result = []
for word in words:
    consecutive_count = 0
    for char in word:
        if char.lower() not in vowels:
            consecutive_count += 1
            if consecutive_count >= 5:
                result.append(word)
                break
        else:
            consecutive_count = 0

# Task 6: Remove elements from result if ASCII value of all characters not between 96 and 122
result = [word for word in result if all(96 < ord(char) < 122 for char in word)]

# Print the result with spaces between elements
print(' '.join(result))
