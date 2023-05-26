def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result


def combination(n, r):
    return factorial(n) // (factorial(r) * factorial(n - r))


w, h = map(int, input().split(" "))
x, y = map(int, input().split(" "))

course1 = combination(x + y - 2, x - 1)
course2 = combination(w + h - x - y, w - x)

print((course1 * course2) % 1000007)
