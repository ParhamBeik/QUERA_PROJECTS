#get the numbers
startingNumber=int(input())
finishingNumber=int(input())
base=int(input())

# turn them into the base required one by one as they go along and add each digit to a total sum
maxValue=0
numberWithMaxValue=0
for number in range(startingNumber+1,finishingNumber):
    valueOfDigit=0
    copyOfNumber=number
    # if the total sum of the digits bigger than the max , add the number to the final resault variable
    while number!=0:
        valueOfDigit+=number%base
        number=number//base
    if valueOfDigit>maxValue:
        maxValue=valueOfDigit
        numberWithMaxValue=copyOfNumber
        
        
print(numberWithMaxValue)