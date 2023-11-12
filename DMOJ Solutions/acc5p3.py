raw_input = __import__("sys").stdin.readline

total = 0
n, k = map(int, raw_input().split())
blocks = []

for x in range(n):
  p,d = map(int, raw_input().split())
  a = p-d
  tup = (p,d,a)
  blocks.append(tup)

blocks = sorted(blocks, key=lambda s:s[2], reverse = True)

index = 0

while index < len(blocks):
  if index < k:
    total += blocks[index][1]
  else:
    total += blocks[index][0]
  index += 1

print(total)