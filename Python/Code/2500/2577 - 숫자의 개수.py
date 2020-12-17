a = 1
for i in range(3):
	t = int(input())
	a *= t
list = [0,0,0,0,0,0,0,0,0,0]
while a:
	list[a % 10] += 1
	a //= 10
for i in range(0, 10):
	print(list[i])