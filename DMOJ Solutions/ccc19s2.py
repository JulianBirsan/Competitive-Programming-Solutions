t = int(input())

output = []

def isPrime(n):

    if n <= 1:
        return False
    if n <= 3:
        return True

    if n % 2 == 0 or n % 3 == 0:
        return False

    i = 5

    while i ** 2 <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False

        i = i + 6

    return True


for i in range(t):
    n = 2 * int(input())

    for x in range(2,n):
        if isPrime(x) and isPrime(n-x):
            output.append([x,n-x])
            break

for i in output:
    print(str(i[0]) + " " + str(i[1]))