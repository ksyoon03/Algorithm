#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> com[101];
// �ִ� 101���� ������ �����ϴ� ���� ����Ʈ
bool check[101];
// �湮 üũ
int cnt = 0;	// ������ ��ǻ�� ��

void bfs(int x) {		// bfs (�ʺ� �켱 Ž��) �Լ�
	queue <int> q;		// BFS Ž���� ���� ť
	q.push(x);		// ���� ��� x�� ť�� ����
	check[x] = true;		// ���� ��� x�� �湮�ߴٰ� ǥ��

	while (!q.empty()) {	// ť�� ������� �ʴٸ�
		int y = q.front();	// ���� Ž�� ���� ��� y�� ť���� ����
		q.pop();	// ���� ���� ť���� ����
		
		for (int i = 0; i < com[y].size(); i++) {		// ���� ��� y�� ����� ��� ������ ��ȸ
			int z = com[y][i];	// �������� �̵��� ���� ��� z
			if (!check[z]) {	//  ���� ��� z�� ���� �湮���� �ʾҴٸ�
				check[z] = true;	// ������� z�� �湮�ߴٰ� ǥ��
				q.push(z);		// ���� ��� z�� ť�� �߰�
				cnt++;	// ������ ��ǻ�� �� + 1
			}
		}
	}
}

int main() {
	int n, m;
	// ��ü ��ǻ�� ��, ��Ʈ��ũ�� ����� ��ǻ�� ��
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;		// ���� ����� �� ��ǻ��
		cin >> a >> b;
		com[a].push_back(b);	// a�� ��ǻ�Ϳ� b�� ��ǻ�� �����
		com[b].push_back(a);	// b�� ��ǻ�Ϳ� a�� ��ǻ�� �����
		// ����� ����
	}
	bfs(1);	// 1�� ��ǻ�ͺ��� ���� �켱 Ž�� ����
	cout << cnt << endl;
}