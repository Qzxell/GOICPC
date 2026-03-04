import sys
input = lambda: sys.stdin.readline().rstrip()

def so():
    n = input().split()
    posi = []
    nega = []
    lis = map(int,input().split())
    for i in lis:
        if i >= 0 :
            posi.append(i)
            continue
        nega.append(i)
    posi.sort()
    nega.sort()

    li = posi[-1] - (nega[0] if len(nega) > 0 else posi[0])
    ans = []
    ind1 = 0
    ind2 = 0
    acu = 0
    while ind1 < len(posi):
        if acu + posi[ind1] < li:
            ans.append(posi[ind1])
            acu = acu + posi[ind1]
            ind1 = ind1 + 1
        elif ind2 < len(nega) :
            ans.append(nega[ind2])
            acu = acu + nega[ind2]
            ind2 = ind2 + 1
        else:
            return "No"
    while ind2 < len(nega):
        if acu + nega[ind2] > -li:
            ans.append(nega[ind2])
            acu = acu + nega[ind2]
            ind2 = ind2 + 1
        else :
            return "No"

    return "Yes\n" + " ".join(map(str,ans))





res_test = []
t = int(input())
for _ in range(t):
    res_test.append(so())
sys.stdout.write("\n".join(map(str, res_test)))
