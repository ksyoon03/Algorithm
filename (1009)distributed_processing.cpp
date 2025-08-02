#include <iostream>
#include <cmath>
using namespace std;

class Computer {
	int num;
public:
	Computer() { num = 0; }
	void setInfo(int a, int b) {
		a %= 10; 
		if (a == 1 || a == 5 || a == 6) {
			num = a;
			return;
		}
		if (b % 4 == 0) b = 4;
		else b %= 4;

		int tmp = 1;
		for (int i = 0; i < b; i++) {
			tmp = tmp * a % 10;
			if (tmp == 0) num = 10;
			else num = tmp;
		}
	}
	int getInfo() { return num; }
};

int main() {
	int t;
	int a, b;
	cin >> t;
	Computer* com = new Computer[t];
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		com[i].setInfo(a, b);
	}
	for (int i = 0; i < t; i++) {
		cout << com[i].getInfo() << endl;
	}
}