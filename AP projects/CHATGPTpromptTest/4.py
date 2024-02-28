# write a python program that gets an integer as input using the simple input() function without writting any message at the terminal and adds all of the divisors of the integer given and if the sum is equal to the integer given , prints "YES" and otherwise prints "NO"


# Get input integer
num = int(input())

# Calculate sum of divisors
divisor_sum = 0
for i in range(1, num):
    if num % i == 0:
        divisor_sum += i

# Check if the sum equals the input integer
if divisor_sum == num:
    print("YES")
else:
    print("NO")
