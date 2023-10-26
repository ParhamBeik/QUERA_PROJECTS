amountOfNumbers=int(input())
myList=[]
[myList.append(int(input(1))) for _ in range(amountOfNumbers)]
print(max(myList))
