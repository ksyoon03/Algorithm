# 10845번 큐

<aside>

정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

- push X: 정수 X를 큐에 넣는 연산이다.
- pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- size: 큐에 들어있는 정수의 개수를 출력한다.
- empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
- front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
</aside>

이 문제는 queue 헤더 파일의 기능들을 if문으로 구현하는 문제이다.

<aside>

큐(Queue) : FIFO(First-In, First-Out)의 형태를 띄는 자료구조

- 첫 번째로 들어간 요소가 첫 번째로 나오는 형태
</aside>

```cpp
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
```
