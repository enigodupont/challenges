file = open("num","r")
runningSum = 0

for line in file:
    runningSum += long(line)

print runningSum

