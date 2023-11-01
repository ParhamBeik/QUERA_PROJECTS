number=int(input())
maxNumber=number
minNumber=number
while(number!=-1):
    newNumber=int(input())
    number=newNumber
    if newNumber>maxNumber and newNumber!=-1:
        maxNumber=newNumber
    elif newNumber<minNumber and newNumber!=-1:
        minNumber=newNumber
print(maxNumber-minNumber)
        