
original_string = "bababa"

LEVEL_2 = {}

def get_strings(string_val):
    string_set = {}
    for i in range(len(string_val)):
        new_str = string_val[:i] + string_val[i+1:]
        string_set[new_str] = 1
    return string_set

LEVEL_1 = get_strings(original_string)

for string_val in LEVEL_1:
    string_set_lvl_2 = get_strings(string_val)
    for value in string_set_lvl_2:
        LEVEL_2[value] = 0

print len(LEVEL_2)


