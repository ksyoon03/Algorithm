# 11650번 좌표 정렬하기

숫자 N이 주어지고, N개의 (x, y) 좌표가 주어진다.

좌표들을 x 좌표부터 오름차순으로 정렬한다.

만약 x좌표가 같을 경우에는 y좌표를 기준으로 정렬하는 프로그램을 만드는 문제다.

해당 문제는 10814번 나이순 정렬하기 문제와 거의 유사한 문제다.

10814번 문제와 마찬가지로 아래의 헤더파일들을 이용하면 손쉽게 문제를 해결할 수 있다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int n;
	int x, y;
	cin >> n;
	vector<pair<int, int>> cord;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		cord.push_back({ x, y });
	}
	stable_sort(cord.begin(), cord.end());
	
	for (auto it : cord) {
		cout << it.first << " " << it.second << "\n";
	}
}
```