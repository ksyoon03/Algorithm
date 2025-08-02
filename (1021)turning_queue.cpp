#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	deque <int> queue;
	for (int i = 0; i < n; i++) {
		queue.push_back(i + 1);
	}

	vector <int> num(m);
	for (int i = 0; i < m; i++) {
		cin >> num[i];
	}

	int index = 0, count = 0;
	for (int i = 0; i < m; i++) {
		auto it = find(queue.begin(), queue.end(), num[i]);
		if (it != queue.end())
			index = distance(queue.begin(), it);
		for (int j = 0; j < n; j++) {
			if (index <= queue.size() / 2) {
				if (num[i] != queue[0]) {
					int front = queue.front();
					queue.pop_front();
					queue.push_back(front);
					count++;
				}
				else if (num[i] == queue[0]) {
					queue.pop_front();
					break;
				}
			}
			if (index > queue.size() / 2) {
				if (num[i] != queue[0]) {
					int back = queue.back();
					queue.pop_back();
					queue.push_front(back);
					count++;
				}
				else if (num[i] == queue[0]) {
					queue.pop_front();
					break;
				}
			}
		}
	}

	cout << count << endl;
}