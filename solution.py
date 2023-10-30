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
    print(newList)
calculator(8,3,[1,2,3,4,5,6,7,8])