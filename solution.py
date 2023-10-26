def calculator(n, m, li):
    newList=[]
    addednumbers=0
    indexNumber=0
    if type(n/m)==int:
        indexNumber=n//m
    else:
        indexNumber=n//m+1
    for _ in range(indexNumber):
        if len(li)>=3:
            for number in range(m):
                addednumbers+=li[number]
                li.pop(number)
            newList.append(addednumbers)
            addednumbers=0
        else:
            for number in range(len(li)-1):
                addednumbers+=li[number]
                li.pop(number)
            newList.append(addednumbers)
            addednumbers=0
    print(newList)
calculator(8,3,[1,2,3,4,5,6,7,8])