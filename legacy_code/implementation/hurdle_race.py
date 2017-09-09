#!/bin/python

_, k = map(int, raw_input().split())
h = max(map(int, raw_input().split()))

print max(0, h - k)
