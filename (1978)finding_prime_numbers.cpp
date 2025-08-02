#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> pnum(n);
	for (int i = 0; i < n; i++) {
		cin >> pnum[i];
	}
	
	int result = 0;
	int count = 0;
	
	for (int i = 0; i < pnum.size(); i++) {
		if (pnum[i] == 2) {
			result++;
		}
		else {
			if (pnum[i] == 1) count++;
			for (int j = 2; j < pnum[i]; j++) {
				if (pnum[i] % j == 0) count++;
			}
			if (count == 0) result++;
		}
		count = 0;
	}
	cout << result << endl;
}