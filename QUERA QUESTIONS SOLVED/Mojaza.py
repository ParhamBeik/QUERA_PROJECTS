ls=input()
myTuple=([],[])
for number in ls:
    if number%2==0:
        myTuple[0].append(number)
    else:
        myTuple[1].append(number)
print(myTuple)