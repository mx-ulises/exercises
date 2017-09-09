from heapq import heapify, heappop, heappush

n, k = 6, 2
A = [3, 2, 1, 2, 1, 1]

operations = 0
heapify(A)

min_1 = heappop(A)
while min_1 < k and len(A) > 0:
    min_2 = heappop(A)
    new_cookie = min_1 + 2*min_2
    heappush(A, new_cookie)
    min_1 = heappop(A)
    operations += 1

if min_1 < k:
    operations = -1
print operations
