def calculator(n, m, li):
    newList=[]
    addedNumbers=0
    numberItertedCount=1
    start=0
    finish=3
    while numberItertedCount!=m and len(li)!=0:
        for number in li[start:finish:]:
            addedNumbers+=number
        start+=m
        finish+=m
        newList.append(addedNumbers)
        addedNumbers=0
        numberItertedCount+=1
    print(newList)
calculator(8,3,[1,2,3,4,5,6,7,8])