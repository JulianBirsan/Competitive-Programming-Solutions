n = int(input())
output = []

for i in range(n):
    m = list(input())

    temp = ''
    d = 0

    while d < len(m):
        a = m[d]
        good = []
        for x in m[d:]:
            if x == a:
                good.append(x)
                d += 1
            else:
                break

        temp += str(len(good)) + " " + a + " "

    output.append(temp.strip())

for b in output:
    print(b)