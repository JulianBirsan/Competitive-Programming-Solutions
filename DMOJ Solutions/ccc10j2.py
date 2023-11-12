a = int(input())
b = int(input())
c = int(input())
d = int(input())
s = int(input())

ni = s // (a+b)

by = s // (c+d)

nit = 0

byt = 0

nit += (a-b)*ni
byt += (c-d)*by

for i in range(s%(a+b)):
    if a > 0:
        a -= 1
        nit += 1
    else:
        nit -= 1

for i in range(s%(c+d)):
    if c > 0:
        c-= 1
        byt += 1
    else:
        byt -=1

if byt > nit:
    print("Byron")
elif nit > byt:
    print("Nikky")
else:
    print("Tied")