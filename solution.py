def calculator(n, m, li):
    newList=[]
    addedNumbers=0
    numberItertedCount=1
    indexCount=0
    while numberItertedCount!=m and len(li)!=0:
        for _ in range(m):
            addedNumbers+=li[indexCount]
        newList.append(addedNumbers)
        addedNumbers=0
        numberItertedCount+=1
    print(newList)
calculator(8,3,[1,2,3,4,5,6,7,8])