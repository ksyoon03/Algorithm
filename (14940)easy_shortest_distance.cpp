#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dy[] = { 1, -1, 0, 0 };	// y�� ��ȭ
int dx[] = { 0, 0, -1, 1 };		// x�� ��ȭ
int board[1001][1001];	// ������ �ִ� ũ��
bool check[1001][1001] = { false };	// �湮 üũ

void bfs(int y, int x) {
	queue <pair<int, int>> q;		// ������ ť
	q.push({ y, x });		// ť�� ����, ���� Ǫ��
	board[y][x] = 0;		// �������� ���� 0
	check[y][x] = true;		// �������� �湮�ߴٰ� ǥ��
	
	while (!q.empty()) {	// ť�� ��� �ݺ� ����
		int cur_y = q.front().first;	// ���� y ��ǥ
		int cur_x = q.front().second;	// ���� x ��ǥ
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];	// y�� ��ȭ
			int nx = cur_x + dx[i];	// x�� ��ȭ
			if (ny >= 0 && ny <= n && nx >= 0 && ny <= m) {
			// �ٲ� ��ǥ�� ���� ���� ���� ��
				if (!check[ny][nx] && board[ny][nx] != 0) {
				// �ٲ� ��ǥ�� ���� �湮���� �ʾҰ�, �Է¹��� ���� 0�� �ƴ� ��
					q.push({ ny, nx });	// ���� Ž���� ���� y, x ���� ť�� Ǫ��
					check[ny][nx] = true;		// �ٲ� ��ǥ�� �湮������ ǥ��
					board[ny][nx] = board[cur_y][cur_x] + 1;
					// �ٲ� ��ǥ�� ������ ��: ���� ��ǥ + 1
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
			// �Է� ���� ��ǥ �����̸�
				y = i;
				x = j;
				// ��ǥ ���� ��ǥ ����
			}
		}
	}
	bfs(y, x);	// bfs Ž�� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && board[i][j] > 0) {
			// �� �� �ִ� �������� ������ �� ���� ��
				cout << -1 << ' ';
			}
			else {
				cout << board[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}