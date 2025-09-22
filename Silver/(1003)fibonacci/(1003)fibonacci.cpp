#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int t;
	cin >> t;

	vector <pair <int, int>> dp(41);
	// n의 크기는 40 이하
	// { 0의 개수, 1의 개수 }

	dp[0] = { 1, 0 };		// 0번째 수열
	dp[1] = { 0, 1 };		// 1번째 수열

	for (int i = 2; i <= 40; i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;		// i번째 수열에서 0의 개수
		dp[i].second = dp[i - 1].second + dp[i - 2].second;	// i번째 수열에서 1의 개수
	}

	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n].first << " " << dp[n].second << endl;	// n번째 수열의 0의 개수와 1의 개수 출력
	}
}
