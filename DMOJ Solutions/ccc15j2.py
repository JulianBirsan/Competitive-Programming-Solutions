happy_count = 0
sad_count = 0
message = input()


if ":-)" in message:

    for letter in message:
        if letter == ")":
            happy_count += 1

if ":-(" in message:
    for letter in message:
        if letter == "(":
            sad_count += 1

if happy_count + sad_count == 0:
    print("none")
elif happy_count == sad_count:
    print("unsure")
elif happy_count > sad_count:
    print("happy")
elif happy_count < sad_count:
    print("sad")