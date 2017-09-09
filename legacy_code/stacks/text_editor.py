# Enter your code here. Read input from STDIN. Print output to STDOUT
operations = []
text = ""

def _append(w):
    return text + w

def _erase(k):
    n = len(text)
    return text[:n - k]

lines = """1 abc
3 3
2 3
1 xy
3 2
4
4
3 1"""
lines = lines.splitlines()

for i in range(len(lines)):
    inputs = lines[i].split()
    op = int(inputs[0])
    if op == 1:
        text = _append(inputs[1])
        operations += [(_erase, len(inputs[1]))]
    if op == 2:
        k = int(inputs[1])
        n = len(text)
        w = text[n - k:]
        operations += [(_append, w)]
        text = _erase(k)
    if op == 3:
        k = int(inputs[1])
        print text[k - 1]
    if op == 4 and operations:
        func, arg = operations.pop()
        text = func(arg)
