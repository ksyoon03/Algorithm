#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dy[] = { 1, -1, 0, 0 };	// y축 변화
int dx[] = { 0, 0, -1, 1 };		// x축 변화
int board[1001][1001];	// 지도의 최대 크기
bool check[1001][1001] = { false };	// 방문 체크

void bfs(int y, int x) {
	queue <pair<int, int>> q;		// 이차원 큐
	q.push({ y, x });		// 큐에 세로, 가로 푸쉬
	board[y][x] = 0;		// 시작점의 값은 0
	check[y][x] = true;		// 시작점을 방문했다고 표시
	
	while (!q.empty()) {	// 큐가 비면 반복 종료
		int cur_y = q.front().first;	// 현재 y 좌표
		int cur_x = q.front().second;	// 현재 x 좌표
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];	// y축 변화
			int nx = cur_x + dx[i];	// x축 변화
			if (ny >= 0 && ny <= n && nx >= 0 && ny <= m) {
			// 바뀐 좌표가 범위 내에 있을 때
				if (!check[ny][nx] && board[ny][nx] != 0) {
				// 바뀐 좌표가 아직 방문하지 않았고, 입력받은 값이 0이 아닐 때
					q.push({ ny, nx });	// 다음 탐색을 위해 y, x 값을 큐에 푸쉬
					check[ny][nx] = true;		// 바뀐 좌표를 방문했음을 표시
					board[ny][nx] = board[cur_y][cur_x] + 1;
					// 바뀐 좌표에 지정된 값: 현재 좌표 + 1
				}
			}
		}
	}
}

int main() {
	int y = 0, x = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
			// 입력 값이 목표 지점이면
				y = i;
				x = j;
				// 목표 지점 좌표 저장
			}
		}
	}
	bfs(y, x);	// bfs 탐색 시작
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && board[i][j] > 0) {
			// 갈 수 있는 땅이지만 도달할 수 없을 때
				cout << -1 << ' ';
			}
			else {
				cout << board[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}
