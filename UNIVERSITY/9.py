firstNumber=int(input())
secondNumber=int(input())
listOfFirstOddNumbers=[]
listOfSecondOddNumbers=[]

variable=10
while variable<=firstNumber*10:
    listOfFirstOddNumbers.append(firstNumber%variable - firstNumber%(variable//10))
    listOfSecondOddNumbers.append(secondNumber%variable - secondNumber%(variable//10))
    variable*=10

emptyBucket=0

for index in range(0,len(listOfFirstOddNumbers),2):
    emptyBucket=listOfFirstOddNumbers[index]
    listOfFirstOddNumbers[index]=listOfSecondOddNumbers[index]
    listOfSecondOddNumbers[index]=emptyBucket
    emptyBucket=0

firstSum=0
secondSum=0

for number in listOfFirstOddNumbers:
    firstSum+=number

for number in listOfSecondOddNumbers:
    secondSum+=number
    
print(firstSum,end=" ")
print(secondSum,end=" ")