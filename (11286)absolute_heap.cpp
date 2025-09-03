#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue <int, vector<int>, greater<int>> plus;	// ��� ť
	// ���� ���� ���� ���� �տ� ��
	priority_queue <int> minus;	// ���� ť
	// ���� ū ���� ���� �տ� �� (�տ� �������� ������ �۾���)
	cin >> n;

	while (n-- > 0) {
		int x;
		cin >> x;

		if (x == 0) {	// x�� 0�� ��
			if (plus.empty() && minus.empty()) {
			// ����� ���� ť�� ��� ���������
				cout << 0 << '\n'; // 0 ���
			}
			else if (plus.empty() && !minus.empty()) {
			// ��� ť�� ���������
				cout << minus.top() << '\n';
				minus.pop();
				// ���� �� ���� ū �� ��� �� ����
			}
			else if (!plus.empty() && minus.empty()) {
			// ���� ť�� ���������
				cout << plus.top() << '\n';
				plus.pop();
				// ��� �� ���� ���� �� ��� �� ����
			}
			else {	// � ť�� ������� ���� ��
				if (plus.top() >= abs(minus.top())) { // abs() : ������ ���ϴ� �Լ�
				// ��� ť�� ���� ���� ���� ���� ť�� ���� ū ���� ���񰪺��� ũ�ų� ������
					cout << minus.top() << '\n';
					minus.pop();
					// ���� ť�� ���� �տ� �ִ� �� ��� �� ����
				}
				else if (plus.top() < abs(minus.top())) {
				// ��� ť�� ���� ���� ���� ���� ť�� ���� ū ���� ���񰪺��� ������
					cout << plus.top() << '\n';
					plus.pop();
					// ��� ť�� ���� �տ� �ִ� �� ��� �� ����
				}
			}
		}
		else {	// x�� 0�� �ƴ� ��
			if (x > 0) {	// x�� 0���� ũ��
				plus.push(x);	// ��� ť�� Ǫ��
			}
			else if (x < 0) {	// x�� 0���� ������
				minus.push(x);	// ���� ť�� Ǫ��
			}
		}
	}
}