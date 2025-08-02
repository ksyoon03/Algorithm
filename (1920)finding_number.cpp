#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	cin >> m;
	vector <int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < b.size(); i++) {
		if (binary_search(a.begin(), a.end(), b[i])) {
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}
}