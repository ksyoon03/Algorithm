# 11286번 절댓값 힙

<aside>

## 문제

절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

1. 배열에 정수 x (x ≠ 0)를 넣는다.
2. 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.

프로그램은 처음에 비어있는 배열에서 시작하게 된다.

</aside>

<aside>

## 입력

첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다.

</aside>

<aside>

## 출력

입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.

</aside>

이 문제는 앞서서 풀었던 최소 힙과 최대 힙 문제를 응용해서 푸는 문제이다.

[1927번 최소 힙](https://www.notion.so/1927-263e73cfe03f80918eaccf378f7bc460?pvs=21)

[11279번 최대 힙](https://www.notion.so/11279-263e73cfe03f806cbe7fd7b0026d03a6?pvs=21)

```cpp
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
```
