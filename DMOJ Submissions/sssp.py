n,m = map(int,input().split())

graph = [[] for i in range(n+1)]

for i in range(m):
    a,b,w = map(int,input().split())

    graph[a].append([b,w])
    graph[b].append([a,w])

inf = 1e9

dist = [inf for i in range(n+1)]
inq = [0 for i in range(n+1)]
q = [1]

dist[1] = 0
inq[1] = 1

while(q):
    at = q.pop(0)
    inq[at] = 0

    for i in graph[at]:
        if dist[at] + i[1] < dist[i[0]]:
            dist[i[0]] = dist[at] + i[1]
            if not inq[i[0]]:
                q.append(i[0])
                inq[i[0]] = 1

for i in range(1,n+1):
    if dist[i] == inf:
        print(-1)
    else:
        print(dist[i])