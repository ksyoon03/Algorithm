#include <iostream>
#include <vector>
using namespace std;

int field[50][50];
int M, N; // 가로, 세로
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
	field[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
			if (field[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	int t, k; // 테스트 케이스, 배추 갯수
	int count; // 지렁이 수
	cin >> t;
	for (int i = 0; i < t; i++) {
		count = 0;
		cin >> M >> N >> k;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				field[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int w, l;
			cin >> w >> l;
			field[w][l] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == 1) {
					dfs(i, j);
					count++;
				}
			}
		}
		cout << count << endl;
	}
}