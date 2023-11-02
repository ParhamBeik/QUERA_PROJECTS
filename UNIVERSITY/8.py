startingNumber=int(input())
finishingNumber=int(input())
numberOfEven=0
numberOfOdd=0

for number in range(startingNumber,finishingNumber+1):
    if number%2==0:
        numberOfEven+=1
    else:
        numberOfOdd+=1

totalSumOdd=1
totalSumEven=1

if startingNumber%2==0 and finishingNumber%2==0:
    for _ in range(numberOfEven):
        totalSumEven*=2
    for _ in range(numberOfOdd):
        totalSumOdd*=2
    print(totalSumEven-totalSumOdd)
    
elif startingNumber%2==1 and finishingNumber%2==1:
    for _ in range(numberOfEven):
        totalSumEven*=2
    for _ in range(numberOfOdd):
        totalSumOdd*=2
    print(totalSumOdd-totalSumEven)
    
elif (startingNumber%2==0 and finishingNumber%2==1) or (startingNumber%2==1 and finishingNumber%2==0):
    print(0)