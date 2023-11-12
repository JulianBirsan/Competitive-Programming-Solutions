n = int(input())

obs = []

for i in range(n):
    obs.append(list(map(int,input().split(" "))))

obs.sort()

c = 0

for i in range(n-1):
    x = abs(obs[i][1] - obs[i+1][1]) / (obs[i+1][0] - obs[i][0])

    if x > c:
        c = x

print(c)