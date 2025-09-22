#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int L, n;
	cin >> L;
	vector <int> S(L);

	for (int i = 0; i < L; i++) {
		cin >> S[i];
	}
	cin >> n;
	sort(S.begin(), S.end());

	for (int i = 0; i < S.size(); i++) {
		if (n == S[i]) {
			cout << 0 << endl;
			return 0;
		}
	}

	int large_min = 1001;
	int small_max = 0;
	for (int num : S) {
		if (num < n) small_max = max(num, small_max);
		if (num > n) large_min = min(num, large_min);
	}

	int count = (n - small_max) * (large_min - n) - 1;
	cout << count << endl;
}
