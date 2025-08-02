#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		string num;
		cin >> num;
		if (num == "0") return 0;

		string re_num = num;
		reverse(re_num.begin(), re_num.end());
		if (num == re_num) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}