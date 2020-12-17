n, m = map(int, input().split())
arr = list(map(int, input().split()))
result = 0
for i in range(len(arr) - 2):
	for j in range (i + 1, len(arr) - 1):
		for k in range(j + 1, len(arr)):
			if result < arr[i] + arr[j] + arr[k] <= m:
				result = arr[i] + arr[j] + arr[k]
			if result == m:
				print(result)
				exit()
print(result)