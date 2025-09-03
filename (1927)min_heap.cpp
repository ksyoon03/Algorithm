#include <iostream>
#include <queue>
#include <vector>
#include <functional> // 우선순위 큐를 사용하기 위한 헤더파일
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	priority_queue <int, vector <int>, greater <int>> q;
	// 우선순위 큐
	cin >> n;

	while (n--) {
		int x;
		cin >> x;

		if (x == 0) {
			if (q.empty()) {
				cout << 0 << '\n';
				continue;
			}
			else {
				cout << q.top() << '\n';
				// 우선순위 큐에서는 .front()가 아닌 .top() 함수를 쓴다.
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
}