number,base=input().split()
base=int(base)
number=int(number)
num=""
while number!=0:
    if(number%base==10):
        num+="A"
    elif(number%base==11):
        num+="B"
    elif(number%base==12):
        num+="C"
    elif(number%base==13):
        num+="D"
    elif(number%base==14):
        num+="E"
    elif(number%base==15):
        num+="F"
    else:
        num+=str(number%base)
    number=number//base
num=num[::-1]
print(num)
    