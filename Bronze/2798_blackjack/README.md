# 2798번 블랙잭

N개의 카드와 숫자 M이 주어진다. N개의 카드 중 3개의 합이 M보다 같거나 작은 수 중 가장 큰 값을 구하는 문제이다. 즉, 블랙잭의 규칙을 수정한 문제이다.

이 문제를 풀 때는 삼중 반복문을 이용하는 것이 편하다.

처음 시도할 때는 다른 문제를 풀 때처럼 이중 반복문만 생각하고, 삼중 반복문을 이용할 생각을 하지 못했는데, 좀 더 열린 사고를 할 필요가 있을 듯하다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;	// N : 카드의 개수, M : 기준 숫자
	cin >> N >> M;
	vector <int> cards(N);

	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	int res = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= M && sum > res) {
					res = sum;
				}
			}
		}
	}
	cout << res << endl;
}
```

```cpp
for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
```

<aside>

i : **0 ~ N-2번**까지 반복
j : **i+1 ~ N-1번**까지 반복

k : **j+1 ~ N번**까지 반복

</aside>

삼중 반복문의 로직은 배열의 요소들이 서로 겹치지 않도록 하는 것이 중요하다.

때문에, 반복문을 위와 같이 만들었다. 정답은 최대, 최소를 구하는 방식으로 구하면 된다.
