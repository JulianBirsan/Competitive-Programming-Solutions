n = int(input())

streams = []

for i in range(n):
    streams.append(int(input()))

x = int(input())

while x != 77:

    if x == 99:
        y = int(input())
        z = int(input())
        streams.insert(y-1,streams[y-1]*(z/100))
        streams[y] -= streams[y-1]

    if x == 88:
        y = int(input())
        streams[y] += streams[y-1]
        streams.remove(streams[y-1])
    x = int(input())

for i in streams:
    print(round(i),end=" ")