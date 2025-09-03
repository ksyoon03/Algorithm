#include <iostream>
#include <queue>
#include <vector>
#include <functional> // �켱���� ť�� ����ϱ� ���� �������
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	priority_queue <int, vector <int>, greater <int>> q;
	// �켱���� ť
	cin >> n;

	while (n--) {
		int x;
		cin >> x;

		if (x == 0) {
			if (q.empty()) {
				cout << 0 << '\n';
				continue;
			}
			else {
				cout << q.top() << '\n';
				// �켱���� ť������ .front()�� �ƴ� .top() �Լ��� ����.
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
}