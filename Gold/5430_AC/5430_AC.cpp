#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		string com, arr;

		cin >> com;
		cin >> n;
		cin >> arr;

		deque <int> p;
		string tmp = "";

		for (char c : arr) {
			if (isdigit(c)) {		
			// isdigit() : 문자가 숫자인지 아닌지 판별하는 함수
			// 숫자라면 true, 아니라면 false 반환
				tmp += c;
			}
			else {
				if (tmp != "") {
					p.push_back(stoi(tmp));
					tmp = "";
				}
			}
		}
		
		bool rev = false;
		bool err = false;

		for (int i = 0; i < com.size(); i++) {
			if (com[i] == 'R') {
				rev = !rev;
			}
			else if (com[i] == 'D') {
				if (p.empty()) {
					err = true; 
					break;
				}
				if (rev) {
					p.pop_back();
				}
				else {
					p.pop_front();
				}
			}
		}
		if (err) {
			cout << "error" << endl;
		}
		else {
			cout << "[";
			if (!p.empty()) {
				if (rev) {
					while (p.size() > 1) {
						cout << p.back() << ",";
						p.pop_back();
					}
					cout << p.back();
				}
				else {
					while (p.size() > 1) {
						cout << p.front() << ",";
						p.pop_front();
					}
					cout << p.front();
				}
			}
			cout << "]" << endl;
		}
	}
}