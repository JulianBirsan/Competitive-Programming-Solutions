a,b = map(int,input().split())

c,d = map(int,input().split())

t = int(input())


#the distance form the start to the end point is the
#difference between the x coordinates + the difference between the y coordinates

dist = abs(a-c) + abs(b-d)

#if the charge isn't big enough for the distance print no
if t < dist:
    print("N")

#otherwise, the charge minus the distance must be an even number
#this is because if it is an even number, you can first reach the end point
#then afterwards you can keep going back and forth between the end point and some other point
#until the charge runs out
elif (t - dist) % 2 == 0: #
    print("Y")

#if the difference is an odd number, then the method previously mentioned does not work
#because the charge will run out when you are not at the end point
else:
    print("N")