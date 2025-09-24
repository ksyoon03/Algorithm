#include <iostream>
using namespace std;

int t, n;
int dp[12];

int main() {
	cin >> t;

	dp[1] = 1;	// 1이 되는 경우의 수는 1 밖에 없음
	dp[2] = 2;
	// 2가 되는 경우의 수: 2가지
	// 1 + 1
	// 2
	dp[3] = 4;
	// 3이 되는 경우의 수: 4가지
	// 1 + 1 + 1
	// 1 + 2
	// 2 + 1
	// 3

	while (t-- > 0) {	
		for (int i = 4; i <= 11; i++) {
			dp[i] = 0;	// 반복 후 배열 초기화
		}
		cin >> n;
		for (int i = 4; i <= n; i++) {
		// dp[1 ~ 3]까지는 이미 있기 때문에 4부터 n까지 반복 시작
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
			// 점화식
		}

		cout << dp[n] << endl;
	}
}