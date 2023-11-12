n = int(input())

output = []
m = input().split(" ")
m = [int(x) for x in m]
m.sort()

if n % 2 == 1:
  x = n//2 + 1
else:
  x = n // 2
count = 1
i = x - 1

while len(output) != len(m):
  output.append(m[i])
  if i < x:
    i += count
  else:
    i -= count
  count += 1
for r in output:
  print(r, end = " ")