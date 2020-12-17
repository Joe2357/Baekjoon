year = int(input())
if not(year % 400) or (not(year % 4) and year % 100):
	print(1)
else:
	print(0)