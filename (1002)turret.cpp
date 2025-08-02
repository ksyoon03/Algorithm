#include <iostream>
#include <cmath>
using namespace std;

class Location {
	double d;
	int x1, x2, y1, y2, r1, r2;
public:
	Location() { d = 1; r1 = 1; r2 = 1; x1 = 1; x2 = 1; y1 = 1; y2 = 1; }
	~Location() {}
	void input() {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	}
	void setd() {
		d = double(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
	}
	double getd() { return d; }
	int getr1() { return r1; }
	int getr2() { return r2; }
};

int main() {
	int t;

	cin >> t;
	Location* location = new Location[t];
	for (int i = 0; i < t; i++) {
		location[i].input();
		location[i].setd();
	}
	double* d = new double[t];
	int* r1 = new int[t];
	int* r2 = new int[t];
	for (int i = 0; i < t; i++) {
		d[i] = location[i].getd();
		r1[i] = location[i].getr1();
		r2[i] = location[i].getr2();
		if (d[i] == 0 && r1[i] == r2[i]) cout << "-1" << endl;
		else if (d[i] > r1[i] + r2[i] || d[i] < abs(r1[i] - r2[i])) cout << "0" << endl;
		else if (d[i] == r1[i] + r2[i] || d[i] == abs(r1[i] - r2[i])) cout << "1" << endl;
		else if (d[i]<r1[i] + r2[i] && d[i]>abs(r1[i] - r2[i])) cout << "2" << endl;
	}

	delete[] location;
	delete[] d;
	delete[] r1;
	delete[] r2;
}