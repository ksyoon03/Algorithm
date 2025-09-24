#include <iostream>
using namespace std;

int dp[1000001];

int main() {
	int n;
	cin >> n;

	dp[1] = 0;	// 1은 나누거나 뺄 수 없기 때문에 0

	for (int i = 2; i <= n; i++) {	// 2부터 반복 시작
		dp[i] = dp[i - 1] + 1;	// i번째 = i-1번째에 저장된 값 + 1
		
		if (i % 2 == 0) {		// i가 2로 나누어 떨어지면
			dp[i] = min(dp[i], dp[i / 2] + 1);
			// i번째 = 원래 i번째 값과 (i / 2번째에 저장된 값 + 1) 중 더 작은 값
		}

		if (i % 3 == 0) {		// i가 3으로 나누어 떨어지면
			dp[i] = min(dp[i], dp[i / 3] + 1);
			// i번째 = 원래 i번째 값과 (i / 3번째에 저장된 값 + 1) 중 더 작은 값
		}
	}

	cout << dp[n] << endl;
	// n번째에 저장된 값 출력
}
