startingNumber=int(input())
finishingNumber=int(input())
numberOfEven=0

for number in range(startingNumber,finishingNumber+1):
    if number%2==0:
        numberOfEven+=1
        
if startingNumber%2==0 and finishingNumber%2==0:
    totalSum=1
    for _ in range(numberOfEven):
        totalSum*=2
    print(totalSum)
    
elif (startingNumber%2==0 and finishingNumber%2==1) or (startingNumber%2==1 and finishingNumber%2==0):
    print(0)