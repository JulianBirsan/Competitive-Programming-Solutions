word = list(input())
a = len(word)
check = True
while True:
    i = 0
    while i + a <= len(word):

        forwards = word[i:i+a]
        backwards = forwards[:]
        backwards.reverse()

        if forwards == backwards:
            check = False
            break

        i += 1

    if check:
        a -= 1

    else:
        break

print(a)