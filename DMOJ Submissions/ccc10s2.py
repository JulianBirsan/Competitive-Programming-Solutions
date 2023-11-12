k = int(input())
dict = {}

for i in range(k):
    a,b = input().split(" ")
    dict[b] = a

binary = input()

while len(binary)>0:
    for i in range(len(binary)):
        if binary[:i] in dict.keys():
            print(dict[binary[:i]],end="")
            binary = binary[i:]
            break
        elif binary in dict.keys():
            print(dict[binary],end="")
            binary = ""
            break