x1=int(input())
y1=int(input())
x2=int(input())
y2=int(input())
x3=int(input())
y3=int(input())
if x1==x2 or x1==x3 or x2==x3:
    print("Vertical!")
elif y1==y2 or y1==y3 or y2==y3:
    print("Horizontal, I can finally cogitate!")
else:
    print("Not this time then!")