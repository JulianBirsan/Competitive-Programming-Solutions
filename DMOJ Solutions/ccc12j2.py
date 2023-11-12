one = int(input())
two = int(input())
three = int(input())
four = int(input())

if one < two < three < four:
    print("Fish Rising")
elif one > two > three > four:
    print("Fish Diving")
elif one == two == three == four:
    print("Fish At Constant Depth")
else:
    print("No Fish")