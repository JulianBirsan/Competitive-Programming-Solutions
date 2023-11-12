n = int(input())
d = int(input())

def reduce(a,b):

    if a < b:

        for i in range(a,1,-1):
            if a % i == 0 and b % i == 0:
                a = a // i
                b = b // i

    else:
        for i in range(b, 1, -1):
            if a % i == 0 and b % i == 0:
                a = a // i
                b = b // i

    return [a,b]

if n != 0:
    res = reduce(n,d)

    n = res[0]

    d = res[1]


mix = n//d

imp = n - (mix*d)

if mix == 0:
    if imp != 0:
        print(str(imp) + "/" + str(d))

    else:
        print(mix)

else:
    if imp != 0:
        print(str(mix) + " " + str(imp) + "/" + str(d))

    else:
        print(mix)