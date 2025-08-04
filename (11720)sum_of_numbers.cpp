#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	string num;
	cin >> n >> num;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i] - '0';
	}
	cout << sum << endl;
}