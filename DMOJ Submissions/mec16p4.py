input = __import__("sys").stdin.readline

class Solve:

    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.edges = []
        self.uf = [-1 for i in range(self.n+1)]
        self.graph = [[] for i in range(self.n+1)]
        self.id = [0 for i in range(self.m)]
        self.par = [0 for i in range(self.n+1)]
        self.ht = [0 for i in range(self.n+1)]
        self.wtpar = [0 for i in range(self.n+1)]
        self.idpar = [0 for i in range(self.n+1)]

    def initEdges(self):
        for i in range(self.m):
            a,b,l = map(int,input().split())
            self.edges.append([l,a,b,i])

        self.edges.sort()

    def find(self, x):
        if self.uf[x] < 0:
            return x
        self.uf[x] = self.find(self.uf[x])
        return self.uf[x]

    def same(self, x, y):
        if self.find(x) == self.find(y):
            return True
        return False

    def unite(self, x , y):
        x = self.find(x)
        y = self.find(y)
        if self.uf[x] > self.uf[y]:
            temp = x
            x = y
            y = temp

        self.uf[x] += self.uf[y]
        self.uf[y] = x

    def kruksal(self):
        for edge in self.edges:
            if not self.same(edge[1],edge[2]):
                self.unite(edge[1],edge[2])
                self.graph[edge[1]].append([edge[0],edge[2],edge[3]])
                self.graph[edge[2]].append([edge[0],edge[1],edge[3]])
                self.id[edge[3]] = 2

    def dfs(self, at, p):
        for edge in self.graph[at]:
            if edge[1] == p:
                continue
            self.par[edge[1]] = at
            self.ht[edge[1]] = self.ht[at]+1
            self.wtpar[edge[1]] = edge[0]
            self.idpar[edge[1]] = edge[2]
            self.dfs(edge[1],at)

    def replace(self):
        for edge in self.edges:
            if self.id[edge[3]] == 0:
                v1 = edge[1]
                v2 = edge[2]
                ids = []
                while self.ht[v1] > self.ht[v2]:
                    if self.wtpar[v1] == edge[0]:
                        ids.append(self.idpar[v1])
                    v1 = self.par[v1]
                while self.ht[v2] > self.ht[v1]:
                    if self.wtpar[v2] == edge[0]:
                        ids.append(self.idpar[v2])
                    v2 = self.par[v2]
                while v1 != v2:
                    if self.wtpar[v1] == edge[0]:
                        ids.append(self.idpar[v1])
                    v1 = self.par[v1]
                    if self.wtpar[v2] == edge[0]:
                        ids.append(self.idpar[v2])
                    v2 = self.par[v2]
                for i in ids:
                    self.id[i] = 1
                if len(ids):
                    self.id[edge[3]] = 1

    def printAns(self):
        for i in range(self.m):
            if self.id[i] == 0:
                print("not useful")
            elif self.id[i] == 1:
                print("so so")
            else:
                print("useful")


N, M = map(int, input().split())

ans = Solve(N,M)
ans.initEdges()
ans.kruksal()
ans.dfs(1,-1)
ans.replace()
ans.printAns()