n = int(input())

ans = n//10

n = n // 10
while n > 0 :
    ans += n//5;
    n = n//5
print(ans)
