#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;	// N : Ä«µåÀÇ °³¼ö, M : ±âÁØ ¼ýÀÚ
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
