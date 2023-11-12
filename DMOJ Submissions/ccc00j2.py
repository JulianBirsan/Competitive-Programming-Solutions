#process input
m = int(input())
n = int(input())

def check(num):
    #function to check if a number is valid

    num = str(num) #we need to convert int to string to loop through digits
    length = len(num) #storing the length of the number for future convenience

    for i in range(length): #loop through digits
        digit = num[i] #current digit stored in this variable

        #to get the index of 'pair' of a number, we take the current index and subtract it from length of number
        #and also substract one (because of 0-indexing)
        #if you are having trouble visualizing this, try some examples on a sheet of paper

        #check for the digit if it's pair is valid
        if digit == '6':
            if num[length - i - 1] != '9':
                return False
        elif digit == '9':
            if num[length - i - 1] != '6':
                return False
        elif digit == '8':
            if num[length - i - 1] != '8':
                return False
        elif digit == '1':
            if num[length - i - 1] != '1':
                return False
        elif digit == '0':
            if num[length - i - 1] != '0':
                return False
        else: #if code reaches here, the current digit isn't a valid digit
            return False

    return True

ans = 0

for i in range(m , n+1): #loop through range
    ans += check(i) #True = 1 and False = 0, so if the function returned True, ans variable will be incremented

print(ans)