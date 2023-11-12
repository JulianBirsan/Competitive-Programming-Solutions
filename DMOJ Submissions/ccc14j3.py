n = int(input())
antonia = 100
david = 100

for x in range(n):
  rolls = input()
  splt = rolls.split(" ")
  if int(splt[0]) > int(splt[1]):
    david -= int(splt[0])
  elif int(splt[0]) < int(splt[1]):
    antonia -= int(splt[1])

print(antonia)
print(david)