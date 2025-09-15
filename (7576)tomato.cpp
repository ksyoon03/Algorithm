#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N;
int unripe = 0; // 안익은 토마토 개수
int cnt = 0;	// 걸린 일수
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int box[1001][1001];
vector <pair<int, int>> v;
queue <pair<int, int >> q;

void bfs() {
	for (int i = 0; i < v.size(); i++) {
	// 배열 v의 크기만큼 반복
		q.push({ v[i].first, v[i].second });
		// 큐에 익은 토마토의 좌표 푸쉬

	}

	while (!q.empty()) {
		int cx = q.front().first;	// 현재 x 값
		int cy = q.front().second;	// 현재 y 값
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];		// 다음 x 값
			int ny = cy + dy[i];	// 다음 y 값
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (box[nx][ny] == 0 && box[nx][ny] != -1) {
				// 다음 좌표에 아직 방문하지 않았고, 기록된 값이 -1이 아닐때
					box[nx][ny] = box[cx][cy] + 1;
					// 다음 좌표에 기록하는 값 = 현재 좌표에 기록된 값 + 1
					q.push({ nx, ny });
					// 큐에 다음 좌표 푸쉬
				}
			}
		}
	}
	return;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
			// 토마토가 익었으면
				v.push_back({ i, j });
				// 배열 v에 익은 토마토의 좌표 푸쉬
			}
			else if (box[i][j] == 0) {
			// 토마토가 안익었고, -1이 아니면
				unripe++;
				// 안익은 토마토 개수 + 1
			}
		}
	}
	if (unripe == 0) {
		// 안익은 토마토가 없으면
		cout << 0 << endl;
		return 0;
		// 0 출력 후 프로그램 종료
	}

	bfs(); // bfs 탐색 실행

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
			// 탐색 후 아직 안익은 토마토가 남아 있으면
				cout << -1 << endl;
				return 0;
				// -1 출력후 프로그램 종료
			}
			cnt = max(cnt, box[i][j]);
			// 박스에 기록된 값 중 가장 큰 값 저장
		}
	}

	cout << cnt - 1 << endl;
	// 시작 좌표의 값이 1이기 때문에 -1을 해줘야함
	// 걸린 날짜 출력
}