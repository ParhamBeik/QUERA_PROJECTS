firstNumber=int(input())
secondNumber=int(input())
listOfFirstOddNumbers=[]
listOfSecondOddNumbers=[]

variable=10
while variable<=firstNumber*10:
    listOfFirstOddNumbers.append(firstNumber%variable - firstNumber%(variable//10))
    listOfSecondOddNumbers.append(secondNumber%variable - secondNumber%(variable//10))
    variable*=10

indexCorrection=100

for index in range(0,len(listOfSecondOddNumbers),2):
    listOfFirstOddNumbers[index]*=indexCorrection
    listOfSecondOddNumbers[index]*=indexCorrection
    
for index in range(2,len(listOfFirstOddNumbers),2):
    listOfFirstOddNumbers[index]=listOfFirstOddNumbers[index]//indexCorrection
    listOfSecondOddNumbers[index]=listOfSecondOddNumbers[index]//indexCorrection
    
print(listOfFirstOddNumbers)
print(listOfSecondOddNumbers)