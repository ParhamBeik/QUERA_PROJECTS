def calculator(n, m, li):
    newList=[]
    numbersThatShouldBeSummed=[]
    addedNumbers=0
    indexCount=0
    while indexCount<len(li):
        while len(numbersThatShouldBeSummed)<3:
            try:
                numbersThatShouldBeSummed.append(li[indexCount])
            except IndexError:
                break
            indexCount+=1
        for number in numbersThatShouldBeSummed:
            addedNumbers+=number
        newList.append(addedNumbers)
        addedNumbers=0
        numbersThatShouldBeSummed.clear()
    indexCount=0
    finalResault=0
    while indexCount<=len(newList):
        finalResault+=newList[indexCount]
        indexCount+=1
        try:
            finalResault=finalResault-newList[indexCount]
        except IndexError:
            break
    print(finalResault)
calculator(8, 1, [1, 2, 3, 4, 5, 6, 7, 8])
