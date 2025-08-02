#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	for (int i = 0; i < 30000; i++) {
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;

		int longest = max({ a, b, c });

		if (longest == a) {
			if (b * b + c * c == a * a) {
				cout << "right" << endl;
			}
			else if (b * b + c * c != a * a) {
				cout << "wrong" << endl;
			}
		}
		else if (longest == b) {
			if (a * a + c * c == b * b) {
				cout << "right" << endl;
			}
			else if (a * a + c * c != b * b) {
				cout << "wrong" << endl;
			}
		}
		else if (longest == c) {
			if (a * a + b * b == c * c) {
				cout << "right" << endl;
			}
			else if (a * a + b * b != c * c) {
				cout << "wrong" << endl;
			}
		}
	}
}