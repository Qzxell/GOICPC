n = int(input())
v = []

for i in range(0,n):
    x = int(input())
    p = 1
    c = 0
    while p % 2 != 0 :
        c += 1
        p/=2

    v.append(c)

for i in range(0,n):
    print(v[i])
