# 1018번 체스판 다시 칠하기

숫자 N, M을 입력받고, N * M 크기의 W, B로 칠해진 체스판을 입력 받는다.

체스판은 기본적으로 “WBWBW” 식으로 이루어져야하기 때문에 입력 받은 체스판이 규칙에서

어긋날 경우 다시 칠해야 한다. 이때 가장 적게 칠하는 방법의 수를 구하는 문제이다.

(개인적으로 굉장히 어려운 문제였다.)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;	// 행, 열
vector <string> board;	// 체스판

string wb[8] = {	// WB로 시작하는 기본 체스판
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string bw[8] = {	// BW로 시작하는 기본 체스판
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int wb_paint(int start_i, int start_j) { // W로 시작하는 경우
	int cnt = 0; // WB 색칠 횟수
	for (int i = 0; i < 8; i++) {	// 행 반복
		for (int j = 0; j < 8; j++) { // 열 반복
			if (board[i + start_i][j + start_j] != wb[i][j]) { // 체스판의 i행과 j열이 wb 배열의 i행, j열과 다를 때
				cnt++; // 횟수 증가
			}
		}
	}
	return cnt;
}

int bw_paint(int start_i, int start_j) {
	int cnt = 0; // BW 색칠 횟수
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i + start_i][j + start_j] != bw[i][j]) { // 체스판의 i행과 j열이 bw 배열의 i행, j열과 다를 때
				cnt++; // 횟수 증가
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	
	board.resize(n);	// 체스판의 행의 길이
	for (int i = 0; i < n; i++) {
		cin >> board[i];	// 체스판 입력
	}

	int min_cnt = 64; // 체스판 넓이 = 8*8

	// 체스판의 길이가 8보다 크기 때문에 행과 열에서 8씩 뺀 값을 반복한다.
	for (int i = 0; i <= n - 8; i++) { // 행 반복
		for (int j = 0; j <= m - 8; j++) { // 열 반복
			int paint_w = wb_paint(i, j); // WB를 칠하는 횟수
			int paint_b = bw_paint(i, j); // BW를 칠하는 횟수
			int tmp = min(paint_w, paint_b); // WB와 BW를 칠하는 횟수 중 더 적은 수를 tmp에 저장
			min_cnt = min(tmp, min_cnt); // tmp와 min_cnt 중 더 작은 수를 min_cnt에 저장
		}
	}
	cout << min_cnt << endl;
}
```

```cpp
// 전역 변수
int n, m;	// 행, 열
vector <string> board;	// 체스판
```

전역 변수로 n, m과 배열 board를 선언한다.

```cpp
string wb[8] = {	// WB로 시작하는 기본 체스판
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string bw[8] = {	// BW로 시작하는 기본 체스판
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
```

전역 변수로 WB로 시작하는 경우의 체스판과 BW로 시작하는 체스판을 생성해 비교할 때 사용한다.

```cpp
int wb_paint(int start_i, int start_j) { // WB로 시작하는 경우
	int cnt = 0; // WB 색칠 횟수
	for (int i = 0; i < 8; i++) {	// 행 반복
		for (int j = 0; j < 8; j++) { // 열 반복
			if (board[i + start_i][j + start_j] != wb[i][j]) { // 체스판의 i행과 j열이 wb 배열의 i행, j열과 다를 때
				cnt++; // 횟수 증가
			}
		}
	}
	return cnt;
}

int bw_paint(int start_i, int start_j) { // BW로 시작하는 경우
	int cnt = 0; // BW 색칠 횟수
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i + start_i][j + start_j] != bw[i][j]) { // 체스판의 i행과 j열이 bw 배열의 i행, j열과 다를 때
				cnt++; // 횟수 증가
			}
		}
	}
	return cnt;
}
```

입력받은 체스판이 WB로 시작하는 경우와 BW로 시작하는 경우로 나누어서 함수를 선언한다.

입력받은 체스판의 행열의 요소와 기본 체스판의 행렬의 요소가 다를 때, 색칠하는 횟수를 증가시킨다.

```cpp
cin >> n >> m;
	
	board.resize(n);	// 체스판의 행의 길이
	for (int i = 0; i < n; i++) {
	cin >> board[i];	// 체스판 입력
}
```

vector 헤더파일에 들어있는 resize() 함수를 이용하여, 체스판의 크기를 입력받은 행렬의 크기로 바꾼후, 체스판을 입력받는다.

```cpp
int min_cnt = 64; // 체스판 넓이 = 8*8
```

체스판 행렬의 넓이는 8 * 8 이므로, 체스판의 색을 모두 다시 칠하는 경우의 최댓값도 64이다.

체스판을 다시 칠하는 경우의 수가 64가 넘지 않도록 최대값을 기본값으로 저장한다.

```cpp
for (int i = 0; i <= n - 8; i++) { // 행 반복
	for (int j = 0; j <= m - 8; j++) { // 열 반복
		int paint_w = wb_paint(i, j); // WB를 칠하는 횟수
		int paint_b = bw_paint(i, j); // BW를 칠하는 횟수
		int tmp = min(paint_w, paint_b); // WB와 BW를 칠하는 횟수 중 더 적은 수를 tmp에 저장
		min_cnt = min(tmp, min_cnt); // tmp와 min_cnt 중 더 작은 수를 min_cnt에 저장
	}
}
```

행과 열의 기본 길이는 8이므로