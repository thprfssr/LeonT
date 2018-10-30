import numpy as np

def lnf(n):
    s = (n + 1/2) * np.log(n) - n + np.log(2 * np.pi) / 2
    return s

i = 94000000000
D = 1E12
value = 1 + D * np.log(10)
s = 0
while s <= value:
    s = lnf(i)
    if i % 1000000 == 1:
        print("i =", i // 1000000, "M\tlnf(i) =", s)
    i += 1
print("i =", i, "lnf(i) =", lnf(i))
