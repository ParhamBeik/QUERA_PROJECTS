numberOfNames=int(input())
listOfNumbersOfChars=[]
for _ in range(numberOfNames):
    listOfChars=[]
    nameOfPerson=input()
    for char in nameOfPerson:
        if char not in listOfChars:
            listOfChars.append(char)
    numberOfCharCount=0
    for char in listOfChars:
        numberOfCharCount+=1
    listOfNumbersOfChars.append(numberOfCharCount)
print(max(listOfNumbersOfChars))
    
