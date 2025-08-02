#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(const pair<int, string> a, const pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int n;
	int age;
	string name;
	cin >> n;
	vector<pair<int, string>> id;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		id.push_back({ age,name });
	}
	stable_sort(id.begin(), id.end(), compare);

	for (auto it : id) {
		cout << it.first << " " << it.second << "\n";
	}
}