nameOfTotalPlayers=["X","Y"]
nameOfPlayerStarted=input()
startingNumber=int(input())
if startingNumber==1:
    print(startingNumber)
numberOfRounds=0 
index=0
while startingNumber!=1:
    if index==0:
        print(startingNumber,end=" ")
        index+=1
    if startingNumber%2==0:
        startingNumber=startingNumber//2
        if startingNumber!=1:
            print(startingNumber,end=" ")
        else:
            print(startingNumber)
        numberOfRounds+=1
    else:
        startingNumber=startingNumber*3+1
        if startingNumber!=1:
            print(startingNumber,end=" ")
        else:
            print(startingNumber)
        numberOfRounds+=1
print(nameOfTotalPlayers[0])