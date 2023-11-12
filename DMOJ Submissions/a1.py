n = int(input())

for i in range(1,n+1):
    s = input()
    ind=0
    for j in range(len(s)):
        if s[j] == " ":
            ind = j
            break
    sp = s.split()
    m = int(sp[0])

    out = ""

    for j in range(ind+1,len(s)):
        m -= 1
        if m!=0:
            out+=s[j]

    print(i,out)