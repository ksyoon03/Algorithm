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
		// 종료 시점을 먼저 넣는다.
	}
	sort(v.begin(), v.end());
	// 종료 시점을 기준으로 오름차순 정렬

	int time = v[0].first;	// 첫 번째 회의의 종료 시간
	int cnt = 1;	// 첫 번째 회의를 마쳤다고 가정하기 때문에 1로 저장
	for (int i = 1; i < n; i++) {
	// 첫 번째 회의를 이미 했기 때문에 i=1부터 반복 시작
		if (time <= v[i].second) {
		// 첫 번째 회의의 종료 시간 <= i번째 회의의 시작 시간
			cnt++;
			time = v[i].first;
			// time = i번째 회의의 종료 시간
		}
	}
	cout << cnt << endl;
}