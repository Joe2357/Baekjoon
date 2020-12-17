notSelf = []
for i in range(1, 10001):
	a = i
	temp = i
	while a > 0:
		temp += a % 10
		a //= 10
	notSelf.append(temp)
for i in range(1, 10001):
	if i not in notSelf:
		print(i)