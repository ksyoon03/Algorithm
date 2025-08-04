#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> s(3);
	while (true) {
		cin >> s[0] >> s[1] >> s[2];
		if (s[0] == 0 && s[1] == 0 && s[2] == 0) return 0;

		sort(s.begin(), s.end());

		int a = s[0], b = s[1], c = s[2];

		if (a * a + b * b == c * c) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}
