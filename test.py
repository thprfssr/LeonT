import math
import datetime


#print("Start:", datetime.datetime.now())
#sum = 0
#for i in range(100000000000):
#    if i % 1000000 == 0:
#        print(i//1000000, "M:\t", sum)
#    sum += math.log(i+1)
#
#print("Final sum:", sum)
#print("End:", datetime.datetime.now())



print("Start:", datetime.datetime.now())

sum = 0
i = 1
D = 1E12
value = 1 + D * math.log(10)
while sum <= value:
    sum += math.log(i)
    if i % 1000000 == 0:
        print("i =", i, "M\tlnf(i) =", sum)
    i += 1

print("The smallest solution to the inequality 1 + D * ln(10) < lnf(n), with D = 1 trillion, is:")
print("n =", sum)
print("End:", datetime.datetime.now())
