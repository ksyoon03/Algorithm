#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int ans = 0;	// ��

void visit(int x, int y, int size) {
	if (x == c && y == r) {
	// ��, ���� ���� ��ġ�� ��
		cout << ans << endl;
		// �� ���
		return;
		// �Լ� ����
	}

	if (c < x + size && c >= x && r < y + size && r >= y) {
	// ã�����ϴ� ���� ������ ���� ���� ���� ��
		size /= 2;	// 2^n-1
		visit(x, y, size);	// 1��и� Ž��
		visit(x + size, y, size);		// 2��и� Ž��
		visit(x, y + size, size);		// 3��и� Ž��
		visit(x + size, y + size, size);	// 4��и� Ž��
	}
	else {	// r, c�� ������ ���� ���� ������ 
		ans += size * size;
		// ���� ��и��� ũ��^2�� �信 ���Ѵ�
	}
}

int main() {
	cin >> n >> r >> c;
	visit(0, 0, pow(2, n));
	// 0��, 0��, 2^n
}