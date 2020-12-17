a = []
for i in range(9):
	a.append(int(input()))
b = a[0]
c = 1
for i in range(len(a)):
	if a[i] > b:
		b = a[i]
		c = i + 1
print("%d\n%d" % (b, c))