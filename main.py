sum = 0
for line in set(open("input.txt", "r").readlines()):
    sum += int(line)
open("output.txt", "w+").write(str(sum))

