#!/bin/python

from factor_operations import Factor, MeasureTable

f1 = Factor("Sexo", ["Hombre", "Mujer"])
f2 = Factor("<18", ["Si", "No"])
f3 = Factor("Cal", ["A", "B", "C"])

MT = MeasureTable([f1, f2, f3])
MT.print_table()
