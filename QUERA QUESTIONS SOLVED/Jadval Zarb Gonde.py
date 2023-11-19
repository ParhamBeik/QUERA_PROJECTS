n=int(input())
round=0
index=0
step=1
while round<n:
    start=1
    start+=round
    index=0
    while index<n:
        print(start,end=" ")
        start+=step
        index+=1
    if index==n:
        print()
    step+=1
    round+=1