k = int(input())
w = input()
output = []
al = ["A","B",'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
a = len(w) - 1
for x in w:
    r = 0
    s = 3*(len(w)-a) + k
    a -= 1
    for l in al:
        if x == l:
            r = al.index(l)

    r -= s

    output.append(al[r])


for n in output:
    print(n,end='')