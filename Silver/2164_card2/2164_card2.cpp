#include <iostream>
#include <queue>	// vector 보다 계산이 빠름
using namespace std;

int main() {
	int N;
	cin >> N;
	queue <int> num;
	for (int i = 1; i <= N; i++) {
		num.push(i);		// 1부터 N까지 순서대로 저장
	}
	
	while (num.size() > 1) {		// 큐의 크기가 1보다 클 동안만 반복
		num.pop();	// 큐의 첫 번째 요소 제거
		num.push(num.front());		// 큐의 첫번째 요소를 마지막 요소로 추가
		num.pop();		// 기존 첫 번째 요소는 제거
	}
	cout << num.front() << endl;
}
