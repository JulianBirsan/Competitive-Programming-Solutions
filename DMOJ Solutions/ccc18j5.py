raw_input = __import__("sys").stdin.readline


n = int(input())


adj_list = {}
track = []

for i in range(n):
    c = list(map(int,raw_input().split(" ")))
    adj_list[i+1] = c[1:]
    track.append(False)

count = 1
q = [1]
layer = 2
fin = False
track[0] = True
q2 = []



while len(q) > 0:

    at = q[0]

    q.remove(q[0])

    for i in adj_list[at]:
        if not track[i-1]:
            if len(adj_list[i]) == 0:
                fin = True
            else:
                q2.append(i)
            track[i-1] = True
            count += 1

    adj_list.pop(at,None)

    if len(q) == 0:
        if len(q2) == 0:
            break
        else:
            q = q2[:]
            q2 = []
            if not fin:
                layer += 1


if count == n:
    print("Y")
else:
    print("N")

print(layer)