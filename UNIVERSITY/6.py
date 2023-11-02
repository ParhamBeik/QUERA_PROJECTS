number=int(input())
numberMinusOne=number-1
firstSum=1
secondSum=1
if number%2==0:
    for variable in range(2,number+1,2):
        firstSum*=variable
    for variable in range(1,numberMinusOne+1,2):
        secondSum*=variable
else:
    for variable in range(1,number+1,2):
        firstSum*=variable
    for variable in range(2,numberMinusOne+1,2):
        secondSum*=variable
print(firstSum-secondSum)