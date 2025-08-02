#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int m, n;
// m : ��
// n : ��
vector <string> board;

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int WB_count(int start_i, int start_j) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[start_i + i][start_j + j] != WB[i][j]) cnt++;
		}
	}
	return cnt;
}

int BW_count(int start_i, int start_j) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[start_i + i][start_j + j] != BW[i][j]) cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); // C�� C++�� ǥ�� ��Ʈ�� ���� ����ȭ�� �����Ͽ� �ӵ� ���
	cin.tie(NULL); // cin�� cout ���� ������ ���� �ӵ� ���

	cin >> m >> n;

	board.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> board[i];
	}

	int min_cnt = 64;

	for (int i = 0; i <= m - 8; i++) {
		for (int j = 0; j <= n - 8; j++) {
			int paint_W = WB_count(i, j);
			int paint_B = BW_count(i, j);
			int tmp = min(paint_W, paint_B);
			min_cnt = min(min_cnt, tmp);
		}
	}
	cout << min_cnt << endl;
}