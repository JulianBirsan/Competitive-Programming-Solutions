teleport = { 9 : 34, 40 : 64, 54 : 19, 67 : 86, 90 : 48, 99 : 77}

at = 1

while True:
    roll = int(input())
    if roll == 0:
        print("You Quit!")
        break
    if(at+roll<=100):
      at += roll
    if at in teleport.keys():
      at = teleport[at]
    
    if at >= 100:
        print("You are now on square 100")
        print("You Win!")
        break
    print("You are now on square " + str(at))