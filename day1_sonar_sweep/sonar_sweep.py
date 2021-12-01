f = open("input.txt", "r")

prev = 0
num = 0
nums = []
for x in f:
    x = int(x)
    if prev > x:
        num += 1
    else:
        if num > 0: nums.append(num)
        num = 0

    prev = x

print(nums)
print(max(nums))

f.close()