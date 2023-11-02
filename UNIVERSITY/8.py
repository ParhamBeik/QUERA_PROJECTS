startingNumber=int(input())
finishingNumber=int(input())
OddNumbers=[]
EvenNumbers=[]
for number in range(startingNumber,finishingNumber+1):
    if number%2==0:
        EvenNumbers.append(number)
    else:
        OddNumbers.append(number)
        
totalSum=1
if len(OddNumbers)==len(EvenNumbers):
    print(0)
elif len(OddNumbers)>len(EvenNumbers):
    difference=len(OddNumbers)-len(EvenNumbers)
    for _ in range(difference):
        totalSum*=2
    print(totalSum)
elif len(OddNumbers)<len(EvenNumbers):
    difference=len(EvenNumbers)-len(OddNumbers)
    for _ in range(difference):
        totalSum*=2
    print(totalSum)
