# write a python program which gets an integer as input using the simple input() function without writting any input massage  and then prints the first n rows of pascals triangle and print the numbers from the left side of the terminal

def generate_pascals_triangle(n):
    triangle = []
    for i in range(n):
        row = [1] * (i + 1)
        for j in range(1, i):
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
        triangle.append(row)
    return triangle

def print_pascals_triangle(triangle):
    width = len(str(triangle[-1][-1]))
    for row in triangle:
        row_str = ' '.join(str(num).rjust(width) for num in row)
        print(row_str.center(len(triangle[-1]) * (width + 1)))

def print_left_aligned(triangle):
    width = len(str(triangle[-1][-1]))
    for row in triangle:
        row_str = ' '.join(str(num).rjust(width) for num in row)
        print(row_str)

if __name__ == "__main__":
    n = int(input())
    triangle = generate_pascals_triangle(n)
    print_left_aligned(triangle)
