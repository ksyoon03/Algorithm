# 10816번 숫자 카드 2

<aside>

숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

</aside>

이 문제는 algorithm 헤더 파일에 들어 있는 **equal_range**를 활용해서 풀었다.

equal_range는 **pair<iterator, iterator>**로 구성되어 있다.

equal range의 첫 번째 이터레이터는 **lower_bound**이고, 두 번째 이터레이터는 **upper_bound** 이다.

<aside>

- **lower_bound** : 찾는 값과 같거나 큰 (≥) 첫 번째 요소의 이터레이터
- **upper_bound** : 찾는 값보다 큰 (>) 첫 번째 요소의 이터레이터
</aside>

equal_range를 활용하기 위해서는 찾고자 하는 값이 있는 배열을 오름차순으로 정렬해주는 것이 좋다.

```cpp
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
```
