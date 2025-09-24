# 1059번 좋은 구간

정수 집합 S가 주어졌을 때, 다음을 만족하는 구간 [A, B]를 좋은 구간이라 한다.

- A와 B는 양의 정수이고, A < B를 만족한다.
- A ≤ n ≤ B를 만족하는 모든 정수 n이 집합 S에 속하지 않는다.
- 집합 S에는 중복되는 정수가 없다.
- 집합 S에 포함된 모든 정수의 범위는 1 ≤ S ≤ 1000 이다.

첫째 줄에 집합 S의 크기 L이 주어진다.

둘째 줄에는 집합에 포함된 정수가 주어진다.

셋째 줄에는 n이 주어진다.

해당 조건을 모두 만족하는 프로그램을 만드는 문제이다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int L, n;
	cin >> L;
	vector <int> S(L);

	for (int i = 0; i < L; i++) {
		cin >> S[i];
	}
	cin >> n;
	sort(S.begin(), S.end());

	for (int i = 0; i < S.size(); i++) {
		if (n == S[i]) {
			cout << 0 << endl;
			return 0;
		}
	}

	int large_min = 1001;
	int small_max = 0;
	for (int num : S) {
		if (num < n) small_max = max(num, small_max);
		if (num > n) large_min = min(num, large_min);
	}

	int count = (n - small_max) * (large_min - n) - 1;
	cout << count << endl;
}
```

집합의 원소들과 정수를 입력받고, 집합을 오름차순으로 정렬한다.

집합 S의 원소들과 정수 n를 비교하여 집합 S에 n과 같은 원소가 있다면 0을 출력하고 프로그램을 종료한다.

```cpp
int large_min = 1001;   // n보다 큰 수 중 가장 작은 값
int small_max = 0;      // n보다 작은 수 중 가장 큰 값
```

변수 large_min에는 집합에서 가장 큰 값이 될 수 있는 1000+1을 저장한다.

변수 small_max에는 집합에서 가장 작은 값이 될 수 있는 1-1을 저장한다.

```cpp
for (int num : S) {
		if (num < n) small_max = max(num, small_max);
		if (num > n) large_min = min(num, large_min);
	}
```

집합 전체를 순회하면서

집합의 원소가 n보다 작을 때는 max() 함수를 활용하여 n보다 작은 가장 큰 값을 small_max 변수에 저장한다.

집합의 원소가 n보다 클 때는 min() 함수를 활용하여 n보다 큰 가장 작은 값을 large_min 변수에 저장한다.

```cpp
int count = (n - small_max) * (large_min - n) - 1;
```

좋은 구간의 개수를 세는 방법은 모든 가능한 구간 [A, B]의 개수를 세는 것이다.

<aside>

n을 포함하는 좋은 구간 [A, B]의 조건

1. A은 (small_max + 1 ~ n**)** 까지 가능 → (**n - small_max) 개**
2. B는 (n ~ large_min - 1**)** 까지 가능    → (**large_min - n) 개**
3. A = n, B = n인 경우 A < B를 만족하지 못함
- **가능한 A와 B의 개수의 곱에 3번 경우의 수를 빼준다.**

### → **A * B - 1 = (n - small_max) * (large_min * n) - 1**

</aside>

위와 같은 방식으로 변수 count를 설정하고, 값을 출력하면 된다.
