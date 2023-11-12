q = int(input())
turn = 1
first = 35 - int(input())
second = 100 - int(input())
third = 10 - int(input())
count = 0

while q > 0:
  q -= 1
  if turn == 1:
    first -= 1
    if first == 0:
      q += 30
      first += 35
    turn = 2
  elif turn == 2:
    second -= 1
    if second == 0:
      q += 60
      second += 100
    turn = 3
  elif turn == 3:
    third -= 1
    if third == 0:
      q += 9
      third += 10
    turn = 1
  count += 1

print("Martha plays " +str(count) + " times before going broke.")