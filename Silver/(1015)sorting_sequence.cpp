#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, input;
	cin >> n;
	vector <int> array;
	vector<pair<int, int>> index;
	for (int i = 0; i < n; i++) {
		cin >> input;
		array.push_back(input);
		index.emplace_back(array[i], i);
	}
	sort(index.begin(), index.end());
	vector <int> result(array.size());
	for (int i = 0; i < n; i++) {
		int idx = index[i].second;
		result[idx] = i;
	}
	for (int idx : result) {
		cout << idx << " ";
	} cout << endl;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Compare {
//
//};
//
//int main() {
//	int n, b;
//	vector <int> arr1;
//	vector <int> arr2;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> b;
//		arr1.push_back(b);
//		arr2.push_back(b);
//	}
//	sort(arr1.begin(), arr1.end());
//	int index = 0;
//	for (int i = 0; i < n; i++) {
//		auto first_it = find(arr1.begin(), arr1.end(), arr2[i]);
//		index = distance(arr1.begin(), first_it);
//
//		if (first_it != arr1.end()) {
//			auto second_it = find(first_it+i, arr1.end(), arr2[i]);
//			if (second_it != arr1.end()) {
//				if (first_it == second_it) {
//					index = distance(arr1.begin(), second_it);
//				}
//			}
//		}
//		cout << index << " ";
//	} cout << endl;
//}
