a, b = input().split()
for i in range(2, -1, -1):
	if a[i] > b[i]:
		for j in range(2, -1, -1):
			print(a[j], end = "")
		break
	elif a[i] < b[i]:
		for j in range(2, -1, -1):
			print(b[j], end = "")
		break