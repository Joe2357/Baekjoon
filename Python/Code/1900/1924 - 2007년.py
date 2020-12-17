a, b = map(int, input().split())
month = [0, 31,28,31,30,31,30,31,31,30,31,30,31]
while a > 0:
	a -= 1
	b += month[a]
b -= 1
day = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
print(day[b % 7])