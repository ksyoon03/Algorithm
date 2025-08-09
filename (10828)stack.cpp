#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack <int> s;
	for (int i = 0; i < n; i++) {
		string com;
		int num;
		cin >> com;
		if (com == "push") {
			cin >> num;
			s.push(num);
		}
		if (com == "pop") {
			if (s.empty()) cout << -1 << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		if (com == "size") {
			cout << s.size() << "\n";
		}
		if (com == "empty") {
			if (s.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		if (com == "top") {
			if (s.empty()) cout << -1 << "\n";
			else cout << s.top() << "\n";
		}
	}
}