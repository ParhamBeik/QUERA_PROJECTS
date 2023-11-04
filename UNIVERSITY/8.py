startingNumber=int(input())
finishingNumber=int(input())
numberOfOddNumbers=0
numberOfEvenNumbers=0
for number in range(startingNumber,finishingNumber+1):
    if number%2==0:
        numberOfEvenNumbers+=1
    else:
        numberOfOddNumbers+=1

totalSum=1

if (startingNumber%2==0 and finishingNumber%2==1) or (startingNumber%2==1 and finishingNumber%2==0):
    print(0)
elif startingNumber%2==0 and finishingNumber%2==0:
    for index in range(numberOfOddNumbers):
        totalSum*=2
elif startingNumber%2==1 and finishingNumber%2==1:
    for index in range(numberOfEvenNumbers):
        totalSum*=2

if totalSum!=1:
    print(totalSum)