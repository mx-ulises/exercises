X = "APBCADCQER"
Y = "RASB"

lcs = [[0 for y in range(len(Y) + 1)] for x in range(len(X) + 1)]

for i in range(1, len(X) + 1):
    for j in range(1, len(Y) + 1):
        if X[i - 1] == Y[j - 1]:
            lcs[i][j] = 1 + lcs[i - 1][j - 1]
        else:
            lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1])

print X
print Y
print ""

for row in lcs:
    print row
