for i in range(int(input())):
	tempArr = list(map(int, input().split()))
	count = tempArr[0]
	del tempArr[0]
	average = float(sum(tempArr) / count)
	people = [a for a in tempArr if a > average]
	print("%.3f%%" % float(len(people) * 100 / count))