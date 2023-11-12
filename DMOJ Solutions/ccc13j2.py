word = input()
use = ["I", "O", "S", "H", "Z", "X", "N"]
count = 0
for a in word:
    if a in use:
        count += 1

if count == len(word):
    print("YES")
else:
    print("NO")