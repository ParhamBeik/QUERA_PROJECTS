def myFunction():
    amountOfNumbers=int(input())
    myList=[]
    [myList.append(int(input())) for _ in range(amountOfNumbers)]
    print(max(myList))
