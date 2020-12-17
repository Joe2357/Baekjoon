remainder = []
for i in range(10):
	temp = int(input())
	if temp % 42 not in remainder:
		remainder.append(temp % 42)
print(len(remainder))