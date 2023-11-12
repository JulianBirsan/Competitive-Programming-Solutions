raw_input = __import__("sys").stdin.readline
n = int(raw_input())
m = []
output = []
for x in range(n):
    m.append(int(raw_input()))

p = []
p.append(m[0])
count = 0
for x in m[1:]:
    p.append(x + p[count])
    count += 1

q = int(input())
for x in range(q):
    a,b = map(int,raw_input().split(" "))
    if a == 0:
        output.append(p[b])
    else:
        output.append(p[b] - p[a-1])
for x in output:
    print(x)