lst = list(map(int, input().split()))
if lst[1] >= lst[2]:
	print(-1)
else:
	print(lst[0] // (lst[2] - lst[1]) + 1)