#include <iostream>
#include <vector>
using namespace std;

int board[128][128];	// �������� ��ü ũ��
int white = 0;	// �Ͼ�� �������� ����
int blue = 0;	// �Ķ��� �������� ����

bool check(int x, int y, int size) {
// ���� ���
// �־��� ���� ������ �������� ���� ��� ������ ���ϴ� �Լ�
	for (int i = x; i < x + size; i++) {
	// x�� �񱳸� ���� �ݺ�
		for (int j = y; j < y + size; j++) {
		// y�� �񱳸� ���� �ݺ�
			if (board[i][j] != board[x][y]) {
			// �־��� ���� ���� ���� ��� ���� ������
			// (��� ���� ���� ���� ���簢���� �ƴ϶��)
				return false;
				// false ��ȯ
			}
		}
	}
	return true;
	// ���� ���� ��� ���� ������ true ��ȯ
}

void paper(int x, int y,int size) {
// ��� �Լ�
// ���簢���� ��� �����̿� �Ķ��� �������� ������ ���ϴ� �Լ�
	if (check(x, y, size)) {
	// �־��� ���� ���� ��� ���� ���� ��
	// (���簢�� �� ��)
		if (board[x][y] == 1) blue++;
		// ù ��° ���� 1�̸� �Ķ��� ����
		else white++;
		// �ƴϸ� ��� ����
		return;
		// �Լ� ����
	}

	size /= 2;
	// �־��� ���� ���� ���� ��� ���� ������
	// ������ ������ ����� �Լ� ȣ�� (��� ȣ��)
	paper(x, y, size);
	paper(x + size, y, size);
	paper(x, y + size, size);
	paper(x + size, y + size, size);
	// �����̸� 4����ؼ� ������ �����Ѵ�.
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	paper(0, 0, n);
	// �������� ù ��° ������ �Լ� ȣ��
	cout << white << '\n';
	cout << blue << '\n';
}