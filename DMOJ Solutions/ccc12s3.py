n = int(input())
dict = {}
for i in range(n):
    r = int(input())
    if r in dict.keys():
        dict[r] += 1
    else:
        dict[r] = 1

one = 0
two = 0
valo = 0
valt = 0


for i in dict.keys():
    if dict[i] > one:
        if one == two:
            if abs(i-valo) >= abs(i-valt):
                valt = valo
            valo = i
            one = dict[i]
        else:
            valt = valo
            two = one
            one = dict[i]
            valo = i
    elif dict[i] == one:
        if one == two:
            a = abs(valo-valt)
            b = abs(i - valo)
            c = abs(i - valt)
            m = max(a,b,c)
            if m == b:
                valt = i
            elif m == c:
                valo = i
        else:
            valt = i
            two = dict[i]
    elif dict[i] > two:
        two = dict[i]
        valt = i
    elif dict[i] == two:
        if(abs(valo-i)>abs(valo-valt)):
            valt = i

print(abs(valo-valt))