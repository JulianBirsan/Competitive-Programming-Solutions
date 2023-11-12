at = int(input())
atwo = int(input())
ao = int(input())
counta = 0
counta += at * 3 + atwo * 2 + ao

bt = int(input())
btwo = int(input())
bo = int(input())
countb = 0
countb += bt * 3 + btwo * 2 + bo

if countb > counta:
    print("B")
elif counta > countb:
    print("A")
else:
    print("T")