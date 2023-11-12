t = int(input())

out = []



for i in range(t):
    n = int(input())

    m = []
    b = []
    l = [0]

    for j in range(n):
        m.append(int(input()))

    m.reverse()

    while True:

        if (m == sorted(m) or m == sorted(m,reverse=True)) and b == sorted(b,reverse=True):
            if len(m) > 0 and len(b) > 0:
                if m[0] == l[-1] + 1 or b[-1] == l[-1] + 1:
                    out.append("Y")
                    break
            else:
                out.append("Y")
                break

        if l[-1] + 1 in m:
            index = m.index(l[-1] + 1)
            b.extend(m[:index])
            del m[0:index]
            l.append(m[0])
            m.remove(m[0])

        else:
            if b[-1] != l[-1] + 1:
                out.append("N")
                break
            l.append(b[-1])
            b.remove(b[-1])

for i in out:
    print(i)