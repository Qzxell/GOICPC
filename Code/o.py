import sys
input = sys.stdin.readline

INF = 1 << 62

def mul(a, b):
    if a <= INF/b :
        return a*b
    return INF

def add(a, b):
    if a == INF or b == INF:
        return INF
    return min(a + b, INF)

def fp(b, e):
    ret = 1
    while e > 0:
        if e & 1:
            ret = mul(ret, b)
        b = mul(b, b)
        e >>= 1
    return ret

def solve():
    s = input().strip()
    q = int(input())
    
    G = [
        [1, 2],
        [2, 0],
        [0, 1]
    ]
    
    for _ in range(q):
        t, k = map(int, input().split())
        
        def fu(pos):
            if pos == -1:
                return False
            if pos == len(s):
                return True
            return k <= mul(pos + 1, fp(2, t))
        
        lo = -1
        lf = len(s)
        
        while lf - lo > 1:
            mid = lo + (lf - lo) // 2
            if fu(mid):
                lf = mid
            else:
                lo = mid
        
        k_local = k - mul(lf, fp(2, t))
        
        print(lf + 1)
        
        cur = ord(s[lf]) - ord('A')
        op = t
        
        while op > 1:
            mi = fp(2, op - 1)
            m1, m2 = G[cur]
            cur = m1
            if k_local > mi:
                k_local -= mi
                cur = m2
            op -= 1
        
        print(chr(cur + ord('A')))

if __name__ == "__main__":
    solve()
