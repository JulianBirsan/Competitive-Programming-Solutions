from sys import stdin
NM = stdin.readline().split(" ")
N = int(NM[0])
M = int(NM[1])
if N > 100000:
    print(N, M)
else:
    visited = [False for i in range(N+1)]
    graph = [[] for i in range(N+1)]
    queue = []
    outcome = "unknown"
    for m in range(M):
        e = stdin.readline().split(" ")
        a = int(e[0])
        b = int(e[1])
        graph[b-1].append(a) # unidirectional graph.
    question = stdin.readline().split(" ")
    A = int(question[0])
    B = int(question[1])
    queue.append(B) # check if A is taller than B first, then check if B is taller than A.
    while len(queue) != 0:
        cE = queue[0]
        queue.pop(0)
        for e in graph[cE-1]:
            if not visited[e]:
                if(e==A):
                    outcome='yes'
                    queue.clear()
                    break
                queue.append(e)
                visited[e]=True
    visited[B]=False
    visited[A]=False
    if outcome == "unknown":
        queue.append(A)
        while len(queue) != 0:
            cE = queue[0]
            queue.pop(0)
            for e in graph[cE-1]:
                if not visited[e]:
                    if(e==B):
                        outcome='no'
                        break
                    queue.append(e)
                    visited[e]=True
    print(outcome)