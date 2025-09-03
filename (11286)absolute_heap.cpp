#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue <int, vector<int>, greater<int>> plus;	// 양수 큐
	// 가장 작은 값이 가장 앞에 옴
	priority_queue <int> minus;	// 음수 큐
	// 가장 큰 값이 가장 앞에 옴 (앞에 있을수록 절댓값이 작아짐)
	cin >> n;

	while (n-- > 0) {
		int x;
		cin >> x;

		if (x == 0) {	// x가 0일 때
			if (plus.empty() && minus.empty()) {
			// 양수와 음수 큐가 모두 비어있으면
				cout << 0 << '\n'; // 0 출력
			}
			else if (plus.empty() && !minus.empty()) {
			// 양수 큐만 비어있으면
				cout << minus.top() << '\n';
				minus.pop();
				// 음수 중 가장 큰 수 출력 후 제거
			}
			else if (!plus.empty() && minus.empty()) {
			// 음수 큐만 비어있으면
				cout << plus.top() << '\n';
				plus.pop();
				// 양수 중 가장 작은 수 출력 후 제거
			}
			else {	// 어떤 큐도 비어있지 않을 때
				if (plus.top() >= abs(minus.top())) { // abs() : 절댓값을 구하는 함수
				// 양수 큐의 가장 작은 값이 음수 큐의 가장 큰 값의 절댓값보다 크거나 같으면
					cout << minus.top() << '\n';
					minus.pop();
					// 음수 큐의 가장 앞에 있는 수 출력 후 제거
				}
				else if (plus.top() < abs(minus.top())) {
				// 양수 큐의 가장 작은 값이 음수 큐의 가장 큰 값의 절댓값보다 작으면
					cout << plus.top() << '\n';
					plus.pop();
					// 양수 큐의 가장 앞에 있는 수 출력 후 제거
				}
			}
		}
		else {	// x가 0이 아닐 때
			if (x > 0) {	// x가 0보다 크면
				plus.push(x);	// 양수 큐에 푸쉬
			}
			else if (x < 0) {	// x가 0보다 작으면
				minus.push(x);	// 음수 큐에 푸쉬
			}
		}
	}
}