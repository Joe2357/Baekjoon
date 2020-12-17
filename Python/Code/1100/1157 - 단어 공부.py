a = input()
list = [0 for i in range(26)]
max = 0
char = ' '
a = a.upper()
for i in range(len(a)):
	list[ord(a[i]) - ord('A')] += 1
	if max < list[ord(a[i]) - ord('A')]:
		max = list[ord(a[i]) - ord('A')]
		char = a[i]
	elif max == list[ord(a[i]) - ord('A')]:
		char = '?'
print(char)