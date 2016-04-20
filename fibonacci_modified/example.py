a, b, n = 0, 1, 5

t_vals = [a, b]
for i in range(n):
    t_i = t_vals[i + 1] * t_vals[i + 1] + t_vals[i]
    t_vals += [t_i]

print t_vals[n -1]
