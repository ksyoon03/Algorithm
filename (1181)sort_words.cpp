#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool custom(const string a, const string b) {
	if (a.length() == b.length()) {
		return a < b;			// ���������� ����
	}
	return a.length() < b.length();		// ���� ������ ����
}

int main() {
	int N;
	cin >> N;
	vector <string> words(N);
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	sort(words.begin(), words.end(), custom);
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());

	for (auto tmp : words) {
		cout << tmp << endl;
	}
}