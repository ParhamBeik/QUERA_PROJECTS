startingNumber=int(input())
finishingNumber=int(input())
base=int(input())

listOfNumbers=[number for number in range(startingNumber+1,finishingNumber)]
sumOfTheDigitsOfNumbers=[]

listOfDigits=[]
for number in range(startingNumber+1,finishingNumber):
    sumOfDigits=0
    while number!=1:
        listOfDigits.append(number%base)
        number=number//base
    for digit in listOfDigits:
        sumOfDigits+=digit
    sumOfTheDigitsOfNumbers.append(sumOfDigits)
    listOfDigits.clear()
    
print(listOfNumbers[sumOfTheDigitsOfNumbers.index(max(sumOfTheDigitsOfNumbers))])
