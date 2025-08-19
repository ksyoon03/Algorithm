#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); // C++ 표준 스트림 동기화 해제
	cin.tie(NULL); // cin과 cout의 연결 해제

	int m;
	int S = 0;
	cin >> m;

	while (m--) {
		string cmd;
		int x;
		cin >> cmd;

		if (cmd == "add") {	// 명령어가 add이면
			cin >> x;
			S |= (1 << (x - 1));	// S의 x번째 비트를 1로 바꾼다.
		}
		else if (cmd == "remove") { // 명령어가 remove이면
			cin >> x;
			S &= ~(1 << (x - 1));	// S의 x번째 비트를 0으로 바꾼다.
		}
		else if (cmd == "check") {	// 명령어가 check일 때,
			cin >> x;
			if (S & (1 << (x - 1))) {	// S의 x번째 비트가 1이면
				cout << 1 << "\n";	// 1을 출력한다.
			}
			else {	// S의 x번째 비트가 0이면
				cout << 0 << "\n";	// 0을 출력한다.
			}
		}
		else if (cmd == "toggle") {	// 명령어가 toggle이면
			cin >> x;
			S ^= (1 << (x - 1));	// x번째 비트가 1이면 0으로, 0이면 1로 변환
		}
		else if (cmd == "all") {	// 명령어가 all이면
			S = (1 << 20) - 1;	// 1~20번째까지의 비트를 전부 1로 바꾼다.
		}
		else if (cmd == "empty") {	// 명령어가 empty이면
			S = 0;	// 1~20번째까지의 비트를 전부 0으로 바꾼다.
		}
	}
}