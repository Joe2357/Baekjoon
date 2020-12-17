alpha = [-1 for i in range(26)]
str = input()
for i in range(len(str)):
	if alpha[ord(str[i]) - ord('a')] is -1:
		alpha[ord(str[i]) - ord('a')] = i
for i in range(26):
	print(alpha[i], end = " ")