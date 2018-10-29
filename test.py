import math
sum = 0
for i in range(100000000000):
    if i % 1000000 == 0:
        print(i//1000000, "M:\t", sum)
    sum += math.log(i+1)

print(sum)
