#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <pair<int, int>> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b, e;
		cin >> b >> e;
		v.push_back({ e, b });
		// ���� ������ ���� �ִ´�.
	}
	sort(v.begin(), v.end());
	// ���� ������ �������� �������� ����

	int time = v[0].first;	// ù ��° ȸ���� ���� �ð�
	int cnt = 1;	// ù ��° ȸ�Ǹ� ���ƴٰ� �����ϱ� ������ 1�� ����
	for (int i = 1; i < n; i++) {
	// ù ��° ȸ�Ǹ� �̹� �߱� ������ i=1���� �ݺ� ����
		if (time <= v[i].second) {
		// ù ��° ȸ���� ���� �ð� <= i��° ȸ���� ���� �ð�
			cnt++;
			time = v[i].first;
			// time = i��° ȸ���� ���� �ð�
		}
	}
	cout << cnt << endl;
}