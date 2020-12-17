for i in range(int(input())):
	a, b = input().split()
	a = int(a)
	for j in range(len(b)):
		print(a * b[j], end = "")
	print()