#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue <int> q;	// 우선순위 큐
	cin >> n;

	while (n-- > 0) {
		int x;
		cin >> x;

		if (x == 0) {
			if (q.empty()) {
				cout << 0 << '\n';
				continue;
			}
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
}