#include <iostream>
#include <string>
#include <vector>;
using namespace std;

string repeat(char S, int R) {
	string result = "";
	for (int i = 0; i < R; i++) {
		result += S;
	}
	return result;
}

int main() {
	int T, R;
	string S;
	cin >> T;

	vector <string> res(T);
	for (int i = 0; i < T; i++) {
		res[i] = "";
		cin >> R >> S;
		for (int j = 0; j < S.length(); j++) {
			res[i] += repeat(S[j], R);
		}
		cout << res[i] << endl;
	}

}
