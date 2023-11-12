v = ["a","e","i","o","u"," "]

output = []

n = int(input())

for i in range(n):
    poem = []
    for j in range(4):
        line = list(input().lower())
        line.reverse()
        poem.append([])

        while True:
            if len(line) == 0:
                break
            poem[-1].append(line[0])
            if line[0] in v:
                break
            line.remove(line[0])

    if poem[0] == poem[1] and poem[0] == poem[2] and poem[0] == poem[3]:
        output.append("perfect")

    elif poem[0] == poem[1] and poem[2] == poem[3]:
        output.append("even")

    elif poem[0] == poem[2] and poem[1] == poem[3]:
        output.append("cross")

    elif poem[0] == poem[3] and poem[1] == poem[2]:
        output.append("shell")

    else:
        output.append("free")

for i in output:
    print(i)