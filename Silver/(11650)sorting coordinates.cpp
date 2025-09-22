#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int n;
	int x, y;
	cin >> n;
	vector<pair<int, int>> cord;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		cord.push_back({ x, y });
	}
	stable_sort(cord.begin(), cord.end());
	
	for (auto it : cord) {
		cout << it.first << " " << it.second << "\n";
	}
}
