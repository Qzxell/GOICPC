import sys
import threading

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    idx = 1
    
    def ft(b, e):
        ret = 1
        while e > 0:
            if e & 1:
                ret = b * ret
            b = b * b
            e >>= 1
        return ret

    outputs = []
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        
        v = []
        
        def f(nu):
            while nu > 0:
                v.append(nu % 3)
                nu //= 3
        
        f(n)
        ans = n
        
        for i in range(len(v)):
            if v[i] == 2:
                ans += ft(3, i)
                if i + 1 < len(v):
                    v[i + 1] += 1
        
        outputs.append(str(ans))
    
    print("\n".join(outputs))

if __name__ == "__main__":
    solve()

