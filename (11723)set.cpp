#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); // C++ ǥ�� ��Ʈ�� ����ȭ ����
	cin.tie(NULL); // cin�� cout�� ���� ����

	int m;
	int S = 0;
	cin >> m;

	while (m--) {
		string cmd;
		int x;
		cin >> cmd;

		if (cmd == "add") {	// ��ɾ add�̸�
			cin >> x;
			S |= (1 << (x - 1));	// S�� x��° ��Ʈ�� 1�� �ٲ۴�.
		}
		else if (cmd == "remove") { // ��ɾ remove�̸�
			cin >> x;
			S &= ~(1 << (x - 1));	// S�� x��° ��Ʈ�� 0���� �ٲ۴�.
		}
		else if (cmd == "check") {	// ��ɾ check�� ��,
			cin >> x;
			if (S & (1 << (x - 1))) {	// S�� x��° ��Ʈ�� 1�̸�
				cout << 1 << "\n";	// 1�� ����Ѵ�.
			}
			else {	// S�� x��° ��Ʈ�� 0�̸�
				cout << 0 << "\n";	// 0�� ����Ѵ�.
			}
		}
		else if (cmd == "toggle") {	// ��ɾ toggle�̸�
			cin >> x;
			S ^= (1 << (x - 1));	// x��° ��Ʈ�� 1�̸� 0����, 0�̸� 1�� ��ȯ
		}
		else if (cmd == "all") {	// ��ɾ all�̸�
			S = (1 << 20) - 1;	// 1~20��°������ ��Ʈ�� ���� 1�� �ٲ۴�.
		}
		else if (cmd == "empty") {	// ��ɾ empty�̸�
			S = 0;	// 1~20��°������ ��Ʈ�� ���� 0���� �ٲ۴�.
		}
	}
}