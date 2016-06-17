def delete_middle(node):
    node.value = node.next.value
    node.next = node.next.next

def get_last_k(initial, k):
    n = 0
    node = initial
    while node
        node = node.next
        n += 1
    node = initial
    for _ in xrange(n - k):
        node = node.next
    return node
