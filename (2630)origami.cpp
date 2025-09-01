#include <iostream>
#include <vector>
using namespace std;

int board[128][128];	// 색종이의 전체 크기
int white = 0;	// 하얀색 색종이의 개수
int blue = 0;	// 파란색 색종이의 개수

bool check(int x, int y, int size) {
// 기저 사례
// 주어진 범위 내에서 색종이의 색이 모두 같은지 비교하는 함수
	for (int i = x; i < x + size; i++) {
	// x값 비교를 위한 반복
		for (int j = y; j < y + size; j++) {
		// y값 비교를 위한 반복
			if (board[i][j] != board[x][y]) {
			// 주어진 범위 내의 색이 모두 같지 않으면
			// (모두 같은 색을 가진 정사각형이 아니라면)
				return false;
				// false 반환
			}
		}
	}
	return true;
	// 범위 내의 모든 색이 같으면 true 반환
}

void paper(int x, int y,int size) {
// 재귀 함수
// 정사각형의 흰색 색종이와 파란색 색종이의 개수를 구하는 함수
	if (check(x, y, size)) {
	// 주어진 범위 내의 모든 색이 같을 때
	// (정사각형 일 때)
		if (board[x][y] == 1) blue++;
		// 첫 번째 값이 1이면 파란색 증가
		else white++;
		// 아니면 흰색 증가
		return;
		// 함수 종료
	}

	size /= 2;
	// 주어진 범위 내의 색이 모두 같지 않으면
	// 범위를 반으로 나누어서 함수 호출 (재귀 호출)
	paper(x, y, size);
	paper(x + size, y, size);
	paper(x, y + size, size);
	paper(x + size, y + size, size);
	// 색종이를 4등분해서 범위를 지정한다.
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	paper(0, 0, n);
	// 색종이의 첫 번째 값으로 함수 호출
	cout << white << '\n';
	cout << blue << '\n';
}