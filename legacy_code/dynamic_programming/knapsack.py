""" Knapsack problem """

BAG = {0: []}
BAG_METRICS = {0: (0, 0)}

ITEMS = [(7, 75), (2, 36), (2, 20), (2, 20), (2, 20)]

BAG_SIZE = 8

# O(n^2)
def get_best_item(items, intersec, size):
    best_item = None
    max_value = -1
    valid_items = list(items)
    for item in intersec:
        valid_items.remove(item)
    for item in valid_items:
        if size >= item[0] and item[1] > max_value:
            best_item = item
            max_value = item[1]
    return best_item

bag_max = BAG[0]
bag_max_weight = BAG_METRICS[0][0]
bag_max_value = BAG_METRICS[0][1]


for size in range(BAG_SIZE + 1):
    best_item = get_best_item(ITEMS, BAG[0], size)
    if best_item:
        bag_max = BAG[0] + [best_item]
        bag_max_weight = BAG_METRICS[0][0] + best_item[0]
        bag_max_value = BAG_METRICS[0][1] + best_item[1]
    for occuped in range(1, size):
        best_item = get_best_item(ITEMS, BAG[occuped], size - occuped)
        if best_item:
            bag_aux = BAG[occuped] + [best_item]
            bag_aux_weight = BAG_METRICS[occuped][0] + best_item[0]
            bag_aux_value = BAG_METRICS[occuped][1] + best_item[1]
            if bag_aux_value > bag_max_value:
                bag_max = bag_aux
                bag_max_weight = bag_aux_weight
                bag_max_value = bag_aux_value
    BAG[size] = bag_max
    BAG_METRICS[size] = (bag_max_weight, bag_max_value)

for i in range(BAG_SIZE + 1):
    print "BAG SIZE: {0}".format(i)
    print "BAG ELEMENTS: {0}".format(BAG[i])
    print "BAG weight: {0}".format(BAG_METRICS[i][0])
    print "BAG value: {0}".format(BAG_METRICS[i][1])
    print ""
