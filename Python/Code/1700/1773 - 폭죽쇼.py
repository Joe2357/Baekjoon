a,b = input().split()
a = int(a)
b = int(b)

lst = [0 for i in range(b)]
result = 0

for i in range(a):
    t = int(input())
    if lst[t - 1] == 1:
        continue
    for j in range(t, b + 1, t):
        if (lst[j-1] == 0):
            result += 1
            lst[j-1] = 1

print(result)