#include <iostream>
#include <vector>
using namespace std;

vector <int> com[101];
// �ִ� 101���� ������ �����ϴ� ���� ����Ʈ
bool check[101];
// �湮 üũ
int cnt = 0;	// ������ ��ǻ�� ��

void dfs(int x) {		// dfs (���� �켱 Ž��) �Լ�
	check[x] = true;		// ���� ��ǻ�Ͱ� ���������� ǥ�� (true)
	for (int i = 0; i < com[x].size(); i++) {	
		// ���� ��ǻ�Ϳ� ��� ��ǻ�͸� ��ȸ
		int y = com[x][i];
		// y = ���� Ž�� ����� x�� ����� ��ǻ��
		if (!check[y]) {
			// y ��ǻ�Ͱ� ���� �������� �ʾҴٸ� (true�� �ƴ϶��)
			dfs(y);	// y��° ��ǻ�ͷ� ���� �켱 Ž�� ����
			cnt++;	// ������ ��ǻ�� �� + 1
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
	dfs(1);	// 1�� ��ǻ�ͺ��� ���� �켱 Ž�� ����
	cout << cnt << endl;
}