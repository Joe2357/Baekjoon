for i in range(int(input())):
	string = input()
	score = 0
	cont_o = 0
	for a in range(len(string)):
		if string[a] == 'O':
			cont_o += 1
		else:
			cont_o = 0
		score += cont_o
	print(score)