first = int(input())
second = first

while True:
    nums = []
    second += 1
    for a in str(second):
        if a not in nums:
            nums.append(a)
    if len(nums) == len(str(second)):
        break

print(second)