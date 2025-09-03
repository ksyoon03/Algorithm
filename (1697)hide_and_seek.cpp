#include <iostream>
#include <queue>
using namespace std;

int n, k;
int board[100001];

int bfs(int n) {
	queue <int> q;
	q.push(n);
	board[n] = 0;
	// ó�� Ž���� �����ϴ� ���� 0���� ����
	
	while (!q.empty()) {	// ť�� ��������� �ݺ� ����
		int current = q.front();	// ���� ��ġ : ť�� ���� �� ���
		q.pop();

		if (current == k) break;	// ���� ��ġ�� k�̸� �ݺ� ����

		int back = current - 1;	// �ڷ� �� ĭ �̵�
		int front = current + 1;	// ������ �� ĭ �̵�
		int warp = current * 2;	// �����̵�

		// �ڷ� �� ĭ �̵�
		if (back > 0 && board[back] == 0) {
		// �ش� ���� 0���� ũ��, ���� �湮���� ���� ��ġ�� ��
			q.push(back);
			// ť�� �ش� ��ġ �߰�
			board[back] = board[current] + 1;
			// back������ �̵� �ð� ��� (���� �ð� + 1)
		}

		// ������ �� ĭ �̵�
		if (front <= 100000 && board[front] == 0) {
		// �ش� ���� 100000���� ũ��, ���� �湮���� ���� ��ġ�� ��
			q.push(front);
			// ť�� �ش� ��ġ �߰�
			board[front] = board[current] + 1;
			// front������ �̵� �ð� ��� (���� �ð� + 1)
		}

		// �����̵�
		if (warp <= 100000 && board[warp] == 0) {
		// �ش� ���� 100000���� ũ��, ���� �湮���� ���� ��ġ�� ��
			q.push(warp);
			// ť�� �ش� ��ġ �߰�
			board[warp] = board[current] + 1;
			// warp������ �̵� �ð� ��� (���� �ð� + 1)
		}
	}

	return board[k];
	// k�� ������ ���� ���� �ð�
}

int main() {
	cin >> n >> k;
	cout << bfs(n) << endl;
}