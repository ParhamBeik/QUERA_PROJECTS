startingNumber=int(input())
finishingNumber=int(input())
base=int(input())
listOfNumbers=[]
for number in range(startingNumber+1,finishingNumber):
    listOfNumbers.append(number)

sumOfTheDigitsOfNumbers=[]
    
listOfDigits=[]

for number in listOfNumbers:
    sumOfDigits=0
    while number!=1:
        listOfDigits.append(number%base)
        number//base
    for digit in listOfDigits:
        sumOfDigits+=digit
    sumOfTheDigitsOfNumbers.append(sumOfDigits)

print(listOfNumbers[sumOfTheDigitsOfNumbers.index(max(sumOfTheDigitsOfNumbers))])