#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue <int> q;
	while (n-- > 0) {
		string com;
		cin >> com;
		if (com == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		if (com == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		if (com == "size") {
			cout << q.size() << "\n";
		}
		if (com == "empty") {
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		if (com == "front") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		if (com == "back") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
	}
}