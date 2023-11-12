tiles = int(input())
root = tiles ** 0.5
rounded = round(root)
if rounded > root:
  rounded -= 1

print("The largest square has side length " + str(rounded) + ".")