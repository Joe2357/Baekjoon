import sys

t = int(input())
for i in range(0, t):
	a, b = sys.stdin.readline().split()
	print(int(a) + int(b))