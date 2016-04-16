
def next_suffix(suffix):
    new_suffix = None
    suffix_list = list(suffix)
    head = suffix_list[0]
    print "Suffix: '{0}'".format(suffix)
    print "Head: '{0}'".format(head)
    new_heads = [i for i in suffix_list if i > head]
    print "New heads: '{0}'".format(new_heads)
    if new_heads:
        new_head = min(new_heads)
        suffix_list.remove(new_head)
        suffix_list.sort()
        new_suffix = new_head + "".join(suffix_list)
    return new_suffix


def get_nex_num(number):
    number_str = str(number)
    number_len = len(number_str)
    for i in range(1, number_len + 1):
        print "Current index: '{0}'".format(i)
        suffix = next_suffix(number_str[number_len - i:])
        if suffix:
            return int(number_str[:number_len - i] + suffix)
    return None


numbers = [231, 1, 121, 5213527, 11111, 3210]
for number in numbers:
    print ""
    print "Number: '{0}', Next: '{1}'".format(number, get_nex_num(number))
