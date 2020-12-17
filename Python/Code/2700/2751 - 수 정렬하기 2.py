import sys

n = int(input())
arr_1 = []
arr_2 = []
for i in range(n):
	temp = int(sys.stdin.readline())
	if i % 2:
		arr_1.append(temp)
	else:
		arr_2.append(temp)
arr_1.sort(reverse = True)
arr_2.sort(reverse = True)
try:
	for i in range(n):
		if arr_1[-1] < arr_2[-1]:
			print(arr_1.pop())
		else:
			print(arr_2.pop())
except:
	if len(arr_1) == 0:
		for i in range(len(arr_2)):
			print(arr_2.pop())
	else:
		for i in range(len(arr_1)):
			print(arr_1.pop())