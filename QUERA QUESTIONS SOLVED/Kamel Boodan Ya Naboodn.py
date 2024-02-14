import math
num = int(input())
copyNum = num 
sum = 0
while copyNum > 1:
    for i in range(2,int(math.sqrt(num))+2,1):
        while copyNum % i==0:
            copyNum= copyNum // i
            sum+=copyNum
    
if sum==num:
    print("YES")

else:
    print("NO")