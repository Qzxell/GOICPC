import sys
input = lambda: sys.stdin.readline().rstrip()

def so():
    n,k,z = map(int,input().split())
    v = list(map(int,input().split()))
    if z == 0:
        acu = 0
        for i in range(k+1):
            acu += v[i]
        return acu
    k = k + 1
    ps = [0]*(n+1)
    for i in range(n):
        ps[i+1] = ps[i] + v[i]

    ans = ps[k]
    for i in range(1,n):
        for j in range(0,z+1):
            if k-2*j >= i + 1 :
                ans = max(ans, j*(v[i]+v[i-1]) + ps[k-2*j])
            if k-2*j > i + 1 and j < z:
                ind = k-2*j - 1
                ans = max(ans, j*(v[i]+v[i-1]) + ps[k-2*j - 1] + max(v[ind],v[ind-2] if ind-2 >= 0 else 0))

    return ans



res_test = []
tt = int(input())
for _ in range(tt):
    res_test.append(so())
sys.stdout.write("\n".join(map(str, res_test))) #output all test
