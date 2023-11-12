N, X = map(int, input().split())

have = {0:1}

prefix = 0
ans = 0

arr = list(map(int,input().split()))

for i in range(N):
  prefix += arr[i]
  if prefix - X in have:
    ans += have[prefix - X]
  if prefix in have:
    have[prefix] += 1
  else:
    have[prefix] = 1

print(ans)