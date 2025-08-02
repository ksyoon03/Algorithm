#include <iostream>
using namespace std;

int main() {
	int n;
	int a, b;
	int count = 0;
	cin >> n >> a >> b;

	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		count++;
	}

	cout << count << endl;
}