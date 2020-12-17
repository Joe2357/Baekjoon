result = 0
for i in range(int(input())):
	alpha = [0 for a in range(26)]
	alp = 0
	bool = True
	str = input()
	for a in range(len(str)):
		if alp is not 0:
			if alpha[ord(str[a]) - ord('a')] and alp is not str[a]:
				bool = False
				break
		alpha[ord(str[a]) - ord('a')] = 1
		alp = str[a]
	if (bool):
		result += 1
print(result)