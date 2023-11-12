n = int(input())
yesterday = input()
today = input()
yesterday = list(yesterday)
today = list(today)
count = 0

while n > 0:
    if yesterday[n - 1] == "C" and today[n - 1] == "C":
        count += 1
    n -= 1


print(count)