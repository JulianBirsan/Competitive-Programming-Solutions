a = 0
b = 0

high = ["jack","queen","king","ace"]
c = []

for i in range(52):
    c.append(input())

for i in range(52):
    point = 0
    if c[i] == "jack" and i <= 50:
        if c[i+1] not in high:
            point = 1

    elif c[i] == "queen" and i <= 49:
        if c[i+1] not in high and c[i+2] not in high:
            point = 2

    elif c[i] == "king" and i <= 48:
        if c[i+1] not in high and c[i+2] not in high and c[i+3] not in high:
            point = 3

    elif c[i] == "ace" and i <= 47:
        if c[i+1] not in high and c[i+2] not in high and c[i+3] not in high and c[i+4] not in high:
            point = 4

    if i % 2 == 0 and point != 0:
        a += point
        print("Player A scores " + str(point) + " point(s).")
    elif i % 2 == 1 and point != 0:
        b += point
        print("Player B scores " + str(point) + " point(s).")

print("Player A: " + str(a) + " point(s).")
print("Player B: " + str(b) + " point(s).")