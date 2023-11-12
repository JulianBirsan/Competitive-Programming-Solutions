d = int(input())
n = d % 720
count = 0
ht = 1
ho = 2
t = 0
o = 0
time = [1,2,0,0]
total = 0
for i in range(n):
    count += 1
    time[3] += 1
    if count % 10 == 0:
        time[3] = 0
        time[2] += 1

    if count > 60 and count < 120:
        time[1] = 1

    if count < 60 or count >= 600:
        time[0] = 1

    else:
        time[0] = 0

    if count % 60 == 0:
        time[1] += 1
        time[2] = 0

    if count == 600:
        time[1] = 0


    if time[0] == 0:
        if time[1] - time[2] == time[2] - time[3]:
            total += 1

    else:
        if time[0] - time[1] == time[1] - time[2] == time[2] - time[3]:
            total += 1


total += 31*(d//720)
print(total)