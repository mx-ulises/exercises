lines = """3
1 5
10 3
3 4
""".splitlines()

n = int(lines[0])
pumps = []

for i in range(n):
    pump = [int(x) for x in lines[i + 1].split()]
    pumps += [pump]

index = 0
tank = 0

for i in range(n):
    tank = tank + pumps[i][0]
    if tank < pumps[i][1]:
        index = i + 1
        tank = 0
    else:
        tank = tank - pumps[i][1]

print index
