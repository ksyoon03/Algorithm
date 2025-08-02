#include <iostream>
using namespace std;

int fac(int n, int m) {
	if (n < 0 || n > m)
		return 0;
	if (n == m || n == 0)
		return 1;
	if (n > m / 2)
		n = m - n;

	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= (m - i);
		result /= (i + 1);
	}
	return result;
}

int main() {
	int t, n, m;
	cin >> t;
	int* result = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		result[i] = fac(n, m);
	}

	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
}