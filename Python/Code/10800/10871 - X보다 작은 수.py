a, b = input().split()
c = list(map(int, input().split()))
for i in range(0, int(a)):
	if(c[i] < int(b)):
		print(c[i], end = " ")