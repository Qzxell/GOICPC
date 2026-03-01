import sys
import math
input = lambda: sys.stdin.readline().rstrip()
inter = lambda a,b: max(a[0],b[0]) <= min(a[1],b[1])
uni = lambda a,b: (min(a[0],b[0]), max(a[1],b[1]))

def so():
    n,d = map(int,input().split())
    seg = []
    for i in range(n):
        lin = list(map(int,input().split()))
        seg.append(lin)
    seg.sort()
    qu = []
    for ele in seg:
        qu.append(ele)
        while len(seg) >= 2:
            fr1 = len.pop()
            fr2 = len.pop()
            if inter(fr1,fr2):
                qu.append(uni(fr1,fr2))
    ans = lenjkk


    return acu



res_test = []
#t = int(input())
t = 1
for _ in range(t):
    res_test.append(so())
sys.stdout.write("\n".join(map(str, res_test))) #output all test
