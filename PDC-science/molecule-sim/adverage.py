with open('simulation_a_10.txt') as fh:
    sum = 0
    numlines = 0
    for line in fh:
        n = line.split(':')[-1]
        sum += float(n)
        numlines += 1
    average = sum / numlines
print( average )
