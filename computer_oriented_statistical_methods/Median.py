import random
import statistics

mylist = []

for i in range(0,20):
    x = random.randint(1,20)
    mylist.append(x)
print(mylist)
mm = statistics.median(mylist)
print(mm)
