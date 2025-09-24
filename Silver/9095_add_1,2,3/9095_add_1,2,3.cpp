#include <iostream>
using namespace std;

int t, n;
int dp[12];

int main() {
	cin >> t;

	dp[1] = 1;	// 1�� �Ǵ� ����� ���� 1 �ۿ� ����
	dp[2] = 2;
	// 2�� �Ǵ� ����� ��: 2����
	// 1 + 1
	// 2
	dp[3] = 4;
	// 3�� �Ǵ� ����� ��: 4����
	// 1 + 1 + 1
	// 1 + 2
	// 2 + 1
	// 3

	while (t-- > 0) {	
		for (int i = 4; i <= 11; i++) {
			dp[i] = 0;	// �ݺ� �� �迭 �ʱ�ȭ
		}
		cin >> n;
		for (int i = 4; i <= n; i++) {
		// dp[1 ~ 3]������ �̹� �ֱ� ������ 4���� n���� �ݺ� ����
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
			// ��ȭ��
		}

		cout << dp[n] << endl;
	}
}