import sys

def so(test):
    n = int(sys.stdin.readline())
    
    tot = n*(n+1)//2 + (n-1)*n//2
    n -= 1
    uwu = n*(n+1)*(n+n+1)//6 + n*(n+1)//2
    
    print(tot + uwu//2)

def main():
    input = sys.stdin.readline
    tt = int(input())
    test = 1
    while tt > 0:
        so(test)
        test += 1
        tt -= 1

if __name__ == "__main__":
    main()
