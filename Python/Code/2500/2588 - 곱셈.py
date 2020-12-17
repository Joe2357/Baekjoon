a = input()
b = input()
a = int(a)
b = int(b)
result = 0
temp = a * (b % 10)
result += temp
print(temp)
b //= 10
temp = a * (b % 10)
result += (temp * 10)
print(temp)
b //= 10
temp = a * b
result += (temp * 100)
print(temp)
print(result)