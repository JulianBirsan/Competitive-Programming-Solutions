n = int(input())
k = int(input())
output = 0
for i in range(k+1):
    output += 10**i*n

print(output)