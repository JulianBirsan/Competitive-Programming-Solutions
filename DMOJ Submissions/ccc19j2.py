l = int(input())

output = []

for i in range(l):
    m = input().split(" ")
    n = int(m[0])
    string = ""
    for a in range(n):
        string += m[1]

    output.append(string)

for x in output:
    print(x)