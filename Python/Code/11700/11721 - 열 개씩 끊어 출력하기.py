str = input()
i = 0
while(i < len(str)):
	print(str[i], end = "")
	i += 1
	if(i % 10 == 0):
		print("")