lst = [3, 3, 3, 4, 4, 4,
	   5, 5, 5, 6, 6, 6,
	   7, 7, 7, 8, 8, 8, 8,
	   9, 9, 9, 10, 10, 10, 10]
str = input()
time = 0
for i in range(len(str)):
	time += lst[ord(str[i]) - ord('A')]
print(time)