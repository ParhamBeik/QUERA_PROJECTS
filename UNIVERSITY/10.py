startingNumber=int(input())
finishingNumber=int(input())
base=int(input())

listOfNumbers=[number for number in range(startingNumber+1,finishingNumber)]
sumOfTheDigitsOfNumbers=[]

for number in range(startingNumber+1,finishingNumber):
    sumOfDigits=0
    while number!=1:
        sumOfDigits+=(number%base)
        number//base
    sumOfTheDigitsOfNumbers.append(sumOfDigits)


    
print(listOfNumbers[sumOfTheDigitsOfNumbers.index(max(sumOfTheDigitsOfNumbers))])
