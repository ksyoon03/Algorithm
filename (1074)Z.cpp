#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int ans = 0;	// 답

void visit(int x, int y, int size) {
	if (x == c && y == r) {
	// 행, 열의 값이 일치할 떄
		cout << ans << endl;
		// 답 출력
		return;
		// 함수 종료
	}

	if (c < x + size && c >= x && r < y + size && r >= y) {
	// 찾고자하는 값이 정해진 범위 내에 있을 때
		size /= 2;	// 2^n-1
		visit(x, y, size);	// 1사분면 탐색
		visit(x + size, y, size);		// 2사분면 탐색
		visit(x, y + size, size);		// 3사분면 탐색
		visit(x + size, y + size, size);	// 4사분면 탐색
	}
	else {	// r, c가 정해진 범위 내에 없으면 
		ans += size * size;
		// 현재 사분면의 크기^2을 답에 더한다
	}
}

int main() {
	cin >> n >> r >> c;
	visit(0, 0, pow(2, n));
	// 0행, 0열, 2^n
}