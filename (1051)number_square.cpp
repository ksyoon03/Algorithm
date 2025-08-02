#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector <string> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int min_s = 1;
	for (int s = min(N, M); s > 0; s--) {
		min_s = s;
		for (int i = 0; i <= N - s; i++) {
			for (int j = 0; j <= M - s; j++) {
				if (num[i][j] == num[i][j + s - 1] &&
					num[i][j] == num[i + s - 1][j] &&
					num[i][j] == num[i + s - 1][j + s - 1]) {
					cout << min_s * min_s << endl;
					return 0;
				}
			}
		}
	}
	cout << min_s * min_s << endl;

	return 0;
}