n = int(input())
result = 0
for i in range(1, n+1):
	if i < 100:
		result += 1
	else:
		a = i // 100
		c = i % 10
		b = ((i - c) // 10) % 10
		if a - b == b - c:
			result += 1
print(result)