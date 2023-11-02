listOfNumbers=[]
number=int(input())
listOfNumbers.append(number)
newNumber=number
while newNumber!=-1:
    newNumber=int(input())
    if newNumber!=-1:
        listOfNumbers.append(newNumber)
totalSum=0
for number in listOfNumbers:
    totalSum+=number
print(totalSum)