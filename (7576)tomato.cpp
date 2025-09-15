#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N;
int unripe = 0; // ������ �丶�� ����
int cnt = 0;	// �ɸ� �ϼ�
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int box[1001][1001];
vector <pair<int, int>> v;
queue <pair<int, int >> q;

void bfs() {
	for (int i = 0; i < v.size(); i++) {
	// �迭 v�� ũ�⸸ŭ �ݺ�
		q.push({ v[i].first, v[i].second });
		// ť�� ���� �丶���� ��ǥ Ǫ��

	}

	while (!q.empty()) {
		int cx = q.front().first;	// ���� x ��
		int cy = q.front().second;	// ���� y ��
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];		// ���� x ��
			int ny = cy + dy[i];	// ���� y ��
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (box[nx][ny] == 0 && box[nx][ny] != -1) {
				// ���� ��ǥ�� ���� �湮���� �ʾҰ�, ��ϵ� ���� -1�� �ƴҶ�
					box[nx][ny] = box[cx][cy] + 1;
					// ���� ��ǥ�� ����ϴ� �� = ���� ��ǥ�� ��ϵ� �� + 1
					q.push({ nx, ny });
					// ť�� ���� ��ǥ Ǫ��
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
			// �丶�䰡 �;�����
				v.push_back({ i, j });
				// �迭 v�� ���� �丶���� ��ǥ Ǫ��
			}
			else if (box[i][j] == 0) {
			// �丶�䰡 ���;���, -1�� �ƴϸ�
				unripe++;
				// ������ �丶�� ���� + 1
			}
		}
	}
	if (unripe == 0) {
		// ������ �丶�䰡 ������
		cout << 0 << endl;
		return 0;
		// 0 ��� �� ���α׷� ����
	}

	bfs(); // bfs Ž�� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
			// Ž�� �� ���� ������ �丶�䰡 ���� ������
				cout << -1 << endl;
				return 0;
				// -1 ����� ���α׷� ����
			}
			cnt = max(cnt, box[i][j]);
			// �ڽ��� ��ϵ� �� �� ���� ū �� ����
		}
	}

	cout << cnt - 1 << endl;
	// ���� ��ǥ�� ���� 1�̱� ������ -1�� �������
	// �ɸ� ��¥ ���
}