lines = """5
8 1
4 2
5 6
3 1
4 3
""".splitlines()

customers = []
n = int(lines[0])

for i in range(n):
    customer = lines[i + 1].split()
    turn = int(customer[0]) + int(customer[1])
    customers += [(i + 1, turn)]

customers = sorted(customers, key=lambda x: x[1])
print " ".join([str(customer[0]) for customer in customers])
