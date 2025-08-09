#include <iostream>
#include <stack>
#include <queue>  // vector�� �̿��ϸ� ���� �����Ϸ������� �ð� �ʰ� �߻�
using namespace std;

int main() {
	int n;
	int cnt = 1;	// push �ؾ��ϴ� ��
	stack <int> s;
	queue <char> res;	// ����� +, -�� ������ ť
	cin >> n;

	for (int i = 0; i < n; i++) {		// n�� �ݺ�
		int x;
		cin >> x;		// pop �ؾ��ϴ� ��

		while (cnt <= x) {		// push �ؾ��ϴ� �� <= pop �ؾ��ϴ� ��
			s.push(cnt);
			cnt++;		// cnt + 1
			res.push('+');		// ���ÿ� push �� ������ ť�� + Ǫ��
		}

		if (s.top() == x) {		// ������ ���� �� ��� = pop �ؾ��ϴ� ���� ��
			s.pop();		// ������ ���� �� ��� ��
			res.push('-');		// ť�� - Ǫ��
		}
		else {	// ������ ���� �� ��Ұ� pop �ؾ��ϴ� ���� �ƴ� ��
			cout << "NO" << "\n";
			return 0;
		}
	}

	while (res.size() > 0) {
		cout << res.front() << "\n";
		res.pop();
	}
}