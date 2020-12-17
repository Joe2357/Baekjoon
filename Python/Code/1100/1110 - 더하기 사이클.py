n = int(input())
i = (n % 10 + n // 10) % 10 + n % 10 * 10
result = 1
while i != n:
	result += 1
	i = i % 10 * 10 + (i % 10 + i // 10) % 10
print(result)