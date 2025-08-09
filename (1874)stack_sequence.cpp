#include <iostream>
#include <stack>
#include <queue>  // vector를 이용하면 백준 컴파일러에서는 시간 초과 발생
using namespace std;

int main() {
	int n;
	int cnt = 1;	// push 해야하는 수
	stack <int> s;
	queue <char> res;	// 출력할 +, -를 저장할 큐
	cin >> n;

	for (int i = 0; i < n; i++) {		// n번 반복
		int x;
		cin >> x;		// pop 해야하는 수

		while (cnt <= x) {		// push 해야하는 수 <= pop 해야하는 수
			s.push(cnt);
			cnt++;		// cnt + 1
			res.push('+');		// 스택에 push 할 때마다 큐에 + 푸쉬
		}

		if (s.top() == x) {		// 스택의 가장 윗 요소 = pop 해야하는 수일 때
			s.pop();		// 스택의 가장 윗 요소 팝
			res.push('-');		// 큐에 - 푸쉬
		}
		else {	// 스택의 가장 윗 요소가 pop 해야하는 수가 아닐 때
			cout << "NO" << "\n";
			return 0;
		}
	}

	while (res.size() > 0) {
		cout << res.front() << "\n";
		res.pop();
	}
}