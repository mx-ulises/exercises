input_str = "We promptly judged antique ivory buckles for the  prize"

char_count = {chr(c): 0 for c in range(ord('a'), ord('z') + 1)}
input_str = input_str.lower()

for i in range(len(input_str)):
    c = input_str[i]
    if 'a' <= c <= 'z':
        char_count[c] += 1

pangram = True
for c in char_count:
    if not char_count[c]:
        pangram = False
        break

if pangram:
    print "pangram"
else:
    print "not pangram"

