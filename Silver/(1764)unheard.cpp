#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;		// µèÀâ
	int m;	// º¸Àâ
	cin >> n >> m;
	
	vector <string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	vector <string> result;
	int count = 0;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			result.push_back(s);
			count++;
		}
	}
	cout << count << endl;
	sort(result.begin(), result.end());
	for (auto it : result) {
		cout << it << endl;
	}
}
