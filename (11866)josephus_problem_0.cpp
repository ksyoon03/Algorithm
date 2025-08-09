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