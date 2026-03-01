import random
import sys

def generate_stress():
    t = 1
    n = 200000
    m = 200000
    
    print(t)
    print(f"{n} {m}")
    
    x_vals = random.sample(range(1, 10**9), n)
    for i in range(n):
        y = random.randint(0, n)
        print(f"{x_vals[i]} {y}")
        
    for _ in range(m):
        x = random.randint(1, 10**9)
        y = random.randint(0, n)
        print(f"{x} {y}")

if __name__ == '__main__':
    # Aumentar limite de recursion por si acaso
    sys.setrecursionlimit(300000)
    generate_stress()
