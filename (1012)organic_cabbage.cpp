#include <iostream>
using namespace std;

int m, n, k;
int field[51][51];		// 배추밭의 최대 크기
int dx[] = { 0, 0, -1, 1 };	// 좌우 x좌표 변화량 (x좌표이므로 상하 값은 0)
int dy[] = { 1, -1, 0, 0 };	// 상하 y좌표 변화량 (y좌표이므로 좌우 값은 0)

void dfs(int x, int y) {
	field[x][y] = 0;
	// DFS 탐색을 실시하자마자 시작 좌표를 방문했음을 표시
	
	for (int i = 0; i < 4; i++) {	// 시작 좌표의 상하좌우 칸 탐색 시작
		int nx = x + dx[i];	// 시작 좌표의 좌우 칸을 탐색
		int ny = y + dy[i];	// 시작 좌표의 상하 칸을 탐색
		if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] == 1) {
		// 시작 좌표의 상하좌우 칸이 배추밭 내에 있고
		// 시작 좌표의 상하좌우 칸 중 값이 1인 칸이 있으면
				dfs(nx, ny);
				// DFS 탐색 실행
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t-- > 0) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			field[x][y] = 1;	// 입력받은 좌표의 값은 모두 1
		}

		int cnt = 0;	// 애벌레의 수
		for (int i = 0; i < m; i++) {		// 배추밭의 바로 길이만큼 반복
			for (int j = 0; j < n; j++) {	// 배추밭의 세로 길이만큼 반복
				if (field[i][j] == 1) {		// 해당 좌표의 값이 1이라면
					cnt++;	// 애벌레 + 1
					dfs(i, j);	// DFS 탐색 실행
				}
			}
		}
		cout << cnt << endl;
	}
}
