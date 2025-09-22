#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;

	if (a >= b) {
		while (b) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	if (b > a) {
		while (a) {
			int temp = a;
			a = b % a;
			b = temp;
		}
		return b;
	}
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
}
