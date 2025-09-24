# 11866번 요세푸스 문제 0

<aside>

요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

</aside>

이 문제는 큐를 응용하여 푸는 문제이다.

<aside>

### 풀이

큐의 K번째 요소에 도달하기 전까지 큐의 첫 번쨰 요소를 맨 뒤로 보내고, 제거하는 것을 반복한다.

K번째 요소에 도달하면 또다른 큐에 해당 요소를 푸쉬하고, 제거한다.

기존 큐의 size()가 0이 될 때까지 반복한다.

</aside>

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	queue <int> res;
	for (int i = 0; i < n; i++) {	// n의 값만큼 반복
		for (int j = 1; j < k; j++)	{	// k의 값보다 1 적게 반복
			q.push(q.front());	// 기존 큐의 첫번째 요소를 맨 뒤에 푸쉬
			q.pop();	// 기존 큐의 첫번째 요소 제거
		}
		res.push(q.front());	// 기존 큐의 k번째 요소를 최종 큐에 푸쉬
		q.pop();	// 기존 큐의 k번째 요소 제거
	}

	cout << "<";
	while (res.size() > 0) {	// 최종 큐의 크기가 0이 될때까지 반복
		if (res.size() > 1) {
			cout << res.front() << ", ";
			res.pop();
		}
		else {
			cout << res.front();
			res.pop();
		}
	}
	cout << ">";
}
```
