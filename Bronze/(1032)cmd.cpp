#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <string> cmd(n);

	for (int i = 0; i < n; i++) {
		cin >> cmd[i];
	}

	string res = cmd[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cmd[0].length(); j++) {
			if (res[j] != cmd[i][j]) {
				res[j] = '?';
			}
		}
	}
	cout << res << endl;
}
