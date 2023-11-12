raw_input = __import__("sys").stdin.readline

weights = []

output = ""

w = int(raw_input())

n = int(raw_input())

for i in range(n):
    weights.append(int(raw_input()))
    tot = 0
    if i >= 3:
        tot += weights[i] + weights[i-1] + weights[i-2] + weights[i-3]

    elif i == 0:
        tot = weights[i]
        
    elif i== 1:
        tot = weights[i] + weights[i-1]
        
    else:
        tot = weights[i] + weights[i-1] + weights[i-2]

    if tot > w:
        output += str(i)
        break

if output == "":
    print(n)

else:
    print(output)