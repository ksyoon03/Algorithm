#include <iostream>
using namespace std;

int fac(int num) {
	int res = 1;
	for (int i = 2; i <= num; i++) {
		res *= i;
	}
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	int res = fac(n) / (fac(k) * fac(n - k));
	cout << res << endl;
}
