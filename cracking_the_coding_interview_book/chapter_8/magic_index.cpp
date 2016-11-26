#include <iostream>

using namespace std;

int magic_index(int* A, int i, int j) {
	if (i == j && A[i] != i)
		return -1;
	int m = (i + j) / 2;
	if (A[m] == m)
		return m;
	if (A[m] < m)
		return magic_index(A, m + 1, j);
	if (m < A[m])
		return magic_index(A, i, m - 1);
}

int get_magic_index(int* A, int n) {
	return magic_index(A, 0, n - 1);
}

void test(int* A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "A["<< i << "]: "<< A[i] << ",  ";
	}
	cout << endl;
	cout << "Magic Index: " << get_magic_index(A, n) << endl << endl;
}

int main() {
	int A[7] = {-1, 0, 2, 4, 5, 8, 9};
	test(A, 7);
	int B[6] = {-1, 1, 4, 7, 8, 9};
	test(B, 6);
	int C[6] = {0, 2, 4, 7, 8, 9};
	test(C, 6);
	int D[4] = {0, 1, 2, 3};
	test(D, 4);
	int E[4] = {1, 2, 3, 4};
	test(E, 4);
	return 0;
}
