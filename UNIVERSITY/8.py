startingNumber=int(input())
finishingNumber=int(input())

if startingNumber%2==0 and finishingNumber%2==0:
    totalSum=1
    for _ in range((finishingNumber-startingNumber)//2):
        totalSum*=2
    print(totalSum)
    
elif (startingNumber%2==0 and finishingNumber%2==1) or (startingNumber%2==1 and finishingNumber%2==0):
    print(0)