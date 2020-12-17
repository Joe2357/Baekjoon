n = int(input())
boolean = True
for i in range(n//5, -1, -1):
	if(not((n - i * 5) % 3)):
		print(i + (n - i * 5) // 3)
		boolean = False
		break
if(boolean):
	print(-1)