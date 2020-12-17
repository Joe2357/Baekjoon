a, b = map(int, input().split())
b -= 45
a -= b < 0
b += 60 * (b < 0)
a += 24 * (a < 0)
print(a, b)