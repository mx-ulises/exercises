#!/bin/python

def solve(year):
    day = 13
    if year < 1918:
        if year % 4 == 0:
            day = 12
    elif 1918 < year:
        if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
            day = 12
    elif year == 1918:
        day = 26
    return "{0}.09.{1}".format(day, year)

year = int(raw_input().strip())
result = solve(year)
print result
