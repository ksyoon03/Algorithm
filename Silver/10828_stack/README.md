# 10828번 스택

<aside>

정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

- push X: 정수 X를 스택에 넣는 연산이다.
- pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- size: 스택에 들어있는 정수의 개수를 출력한다.
- empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
- top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
</aside>

이 문제는 stack 헤더 파일의 기능들을 if문으로 구현하는 문제이다.

<aside>

스택(Stack) : LIFO (Last-In, First-Out)의 형태를 띄는 자료구조

- 마지막에 들어간 요소가 첫번째로 나오는 형태
</aside>

[stack 헤더 파일](https://www.notion.so/stack-24ae73cfe03f8000b86bfaea8911e9cf?pvs=21)

```cpp
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
```
