def calculator(n,m,li):
    
    newList=[]

    while len(li)>=m:
        sum=0
        for _ in range(m):
            sum+=li[0]
            li.pop(0)
        newList.append(sum)
        
    while len(li)>0 and len(li)<m:
        sum=0
        for _ in range(len(li)):
            sum+=li[0]
            li.pop(0)
        newList.append(sum)
        
    index=0
    sum=0
    for i in newList:
        if index%2==0:
            sum+=i
            index+=1
        else:
            sum=sum-i
            index+=1
            
    return sum
