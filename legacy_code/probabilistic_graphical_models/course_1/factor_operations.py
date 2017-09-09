#!/bin/python

class Factor():
    def __init__(self, name, values):
        if len(values) == 0:
            return None
        self.name = name
        self._values = values
        self._reverse_mapping = {values[i]: i for i in xrange(len(values))}

    def count_values(self):
        return len(self._values)

    def get_value(self, i):
        return self._values[i]

    def get_index(self, value):
        return self._reverse_mapping[value]


class MeasureTable():
    def __init__(self, factor_list):
        self.factor_list = factor_list
        column_count = len(factor_list) + 1
        row_count = self._table_rows()
        total_rows = row_count
        self._table = [[0] * column_count for _ in xrange(row_count)]
        for j in xrange(len(factor_list)):
            count_values = factor_list[j].count_values()
            i = 0
            factor_value_index = 0
            total_rows = total_rows / count_values
            while i < row_count:
                for _ in xrange(total_rows):
                    self._table[i][j] = factor_value_index % count_values
                    i += 1
                factor_value_index += 1

    def _table_rows(self):
        i = 1
        for factor in self.factor_list:
            i *= factor.count_values()
        return i

    def print_table(self):
        print "\t".join([factor.name for factor in self.factor_list] + ["percent"])
        for row in self._table:
            row_string = []
            for i in xrange(len(row) - 1):
                data = self.factor_list[i].get_value(row[i])
                row_string.append(str(data))
            row_string.append(str(row[-1]))
            print "\t".join(row_string)
