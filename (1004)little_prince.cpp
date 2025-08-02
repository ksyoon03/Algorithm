#include <iostream>
#include <cmath>
using namespace std;

class Coordinate {
	int cx, cy, r;
public:
	void setInfo(int cx, int cy, int r) {
		this->cx = cx; this->cy = cy; this->r = r;
	}
	int getcx() { return cx; }
	int getcy() { return cy; }
	int getr() { return r; }
};

int main() {
	int t, n;
	int x1, y1, x2, y2;
	int cx, cy, r;
	double d1, d2;

	cin >> t;
	int* count = new int[t];
	for (int i = 0; i < t; i++) {
		count[i] = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		Coordinate* c = new Coordinate[n];
		for (int j = 0; j < n; j++) {
			cin >> cx >> cy >> r;
			c[j].setInfo(cx, cy, r);
			cx = c[j].getcx();
			cy = c[j].getcy();
			r = c[j].getr();
			d1 = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));
			d2 = sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2));

			if (d1 > r && d2 < r) count[i]++;
			else if (d1<r && d2>r) count[i]++;
		}
		delete[] c;
	}

	for (int i = 0; i < t; i++) {
		cout << count[i] << endl;
	}
}