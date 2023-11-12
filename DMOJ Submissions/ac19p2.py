n = int(input())
l = int(input())
s = list(input())
c = n
al = ["a","b",'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

for i in s:
    if i not in al:
        n -= 1
    else:
        for k in al:
            if k == i:
                r = al.index(k)

                if r + l > 25:
                    r = (r + l) % 26


                else:
                    r += l

                s[c - n] = al[r]
                n-=1


for i in s:
    print(i,end='')