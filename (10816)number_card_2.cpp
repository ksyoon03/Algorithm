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
	sort(a.begin(), a.end());		// equal_range()를 사용하기 위해 오름차순으로 정렬한다.

	cin >> m;
	vector <int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < m; i++) {
		auto cnt = equal_range(a.begin(), a.end(), b[i]);
		// equal_range = pair<lower_bound, upper_bound>
		// cnt.first = b[i] 보다 크거나 같은 첫 번째 요소의 이터레이터
		// cnt.second = b[i] 보다 큰 첫 번째 요소의 이터레이터

		cout << distance(cnt.first, cnt.second) << " ";
		// pair<> 형태를 사용하기 때문에 .first와 .second를 사용해 출력한다.
	}
}