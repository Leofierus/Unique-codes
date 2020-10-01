import random
import statistics

li = []

for i in range(0,20):
    x = random.randint(1,20)
    li.append(x)
mm = statistics.mean(li)
print(mm)
