"""
Example of input:
    t
    n_1
    a_1 a_2 ... a_n_1
    .
    .
    n_t
    a_1 a_2 ... a_n_t
"""

input_file = """2
3
1 2 3
5
1 2 3 4 5
""".splitlines()

t = int(input_file.pop(0))
for _ in range(t):
    n = int(input_file.pop(0))
    nums = [int(x) for x in input_file.pop(0).split()]

    map_nums = {x: 0 for x in nums}
    for i in range(n):
        map_nums[nums[i]] += (i + 1) * (n - i)

    for x in map_nums:
        map_nums[x] = map_nums[x] % 2

    result = 0
    for x in map_nums:
        if map_nums[x]:
            result = result ^ x

    print result
