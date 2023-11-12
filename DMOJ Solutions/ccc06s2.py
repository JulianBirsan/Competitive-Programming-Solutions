plain = input()
cipher = input()
output = input()
dict = {}
out = ""

for i in range(len(plain)):
    a = plain[i]
    b = cipher[i]
    dict[b] = a

for i in output:
    if i not in dict.keys():
        out += "."
    else:
        out += dict[i]

print(out)