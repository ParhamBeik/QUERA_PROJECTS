def calculator(n, m, li):
    newList=[]
    addedNumbers=0
    if len(li)>=m:
        for number in range(m):
            addedNumbers+=li[number]
        newList.append(addedNumbers)
        for number in range(m):
            li.pop(number)
        addedNumbers=0
    else:
        for number in range(len(li)):
            addedNumbers+=li[number]
        newList.append(addedNumbers)
    print(newList)
calculator(8,3,[1,2,3,4,5,6,7,8])