#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());		// equal_range()�� ����ϱ� ���� ������������ �����Ѵ�.

	cin >> m;
	vector <int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < m; i++) {
		auto cnt = equal_range(a.begin(), a.end(), b[i]);
		// equal_range = pair<lower_bound, upper_bound>
		// cnt.first = b[i] ���� ũ�ų� ���� ù ��° ����� ���ͷ�����
		// cnt.second = b[i] ���� ū ù ��° ����� ���ͷ�����

		cout << distance(cnt.first, cnt.second) << " ";
		// pair<> ���¸� ����ϱ� ������ .first�� .second�� ����� ����Ѵ�.
	}
}