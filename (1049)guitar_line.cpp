#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; // 필요한 기타줄 개수
	int M; // 브랜드 개수
	cin >> N >> M;
	vector <int> pack(M); // 패키지 가격
	vector <int> each(M); // 개별 가격

	int pack_min = 1000;
	int each_min = 1000;
	for (int i = 0; i < M; i++) {
		cin >> pack[i] >> each[i];

		pack_min = min(pack[i], pack_min);
		each_min = min(each[i], each_min);
	}

	int res = 0;
	if (pack_min <= each_min * 6) {
		res += pack_min * (N / 6);

		if (each_min * (N % 6) > pack_min) res += pack_min;
		else res += each_min * (N % 6);
	}
	else {
		res = each_min * N;
	}

	cout << res << endl;
}