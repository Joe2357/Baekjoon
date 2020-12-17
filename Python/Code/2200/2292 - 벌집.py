n = int(input())
start = 1
std = 0
result = 1
while start < n:
	std += 6; start += std; result += 1
print(result)