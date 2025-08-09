#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	queue <int> res;
	for (int i = 0; i < n; i++) {	// n�� ����ŭ �ݺ�
		for (int j = 1; j < k; j++)	{	// k�� ������ 1 ���� �ݺ�
			q.push(q.front());	// ���� ť�� ù��° ��Ҹ� �� �ڿ� Ǫ��
			q.pop();	// ���� ť�� ù��° ��� ����
		}
		res.push(q.front());	// ���� ť�� k��° ��Ҹ� ���� ť�� Ǫ��
		q.pop();	// ���� ť�� k��° ��� ����
	}

	cout << "<";
	while (res.size() > 0) {	// ���� ť�� ũ�Ⱑ 0�� �ɶ����� �ݺ�
		if (res.size() > 1) {
			cout << res.front() << ", ";
			res.pop();
		}
		else {
			cout << res.front();
			res.pop();
		}
	}
	cout << ">";
}