#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());	// 오름차순 정렬

	int sum = 0;	// 누적 합
	int res = 0;	// 결과 값
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];	// 현재 원소까지 누적 합을 계산
		res += sum;	// 결과값에 누적 합을 더함
	}

	cout << res << endl;
}
