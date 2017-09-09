#!/bin/python

n = int(raw_input())

for _ in xrange(n):
    grade = int(raw_input())
    if grade < 38:
        print grade
    else:
        new_grade = ((grade / 5) + 1) * 5
        if (new_grade - grade) < 3:
            print new_grade
        else:
            print grade
