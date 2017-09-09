#!/bin/python

def check(nums):
    for i in xrange(1, len(nums)):
        if nums[i - 1] > nums[i]:
            return False
    return True

def check_swap(l, r, nums):
    nums_2 = list(nums)
    nums_2[l], nums_2[r] = nums_2[r], nums_2[l]
    return check(nums_2)

def check_reverse(l, r, nums):
    nums_r = nums[l: r + 1]
    nums_r.reverse()
    nums_2 = nums[:l] + nums_r + nums[r + 1:]
    return check(nums_2)

n = 6
nums = map(int, "1 5 4 3 2 6".split())

l = -1
r = -1

for i in xrange(1, n):
    if nums[i - 1] > nums[i]:
        if l < 0:
            l = i - 1
        r = i

if check_swap(l, r, nums):
    print "yes"
    print "swap {0} {1}".format(l + 1, r + 1)
elif check_reverse(l, r, nums):
    print "yes"
    print "reverse {0} {1}".format(l + 1, r + 1)
else:
    print "no"
