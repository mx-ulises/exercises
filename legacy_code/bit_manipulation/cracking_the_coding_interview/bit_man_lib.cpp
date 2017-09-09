int clear_number(int a, int index) {
    int c = 1 << (index + 1);
    int a_mask = c + get_bit(a, index) - 1;
    a = a & ~a_mask;
    return a;
}

int is_negative(int a) {
    int mask = numeric_limits<int>::max();
    int value = a & ~mask;
    int index = (int) log2(mask) + 1;
    return (value >> index) & 1;
}

int get_bit(int a, int index) {
	int mask = 1 << index;
	mask = a & mask;
	mask = mask >> index;
	return mask;
}
