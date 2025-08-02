#include <iostream>
#include <vector>
using namespace std;

int getCount(int num, int t) {
	int countT = 0;
	if (num % t == 0) countT += num / t;
	else if (num % t != 0) countT += num / t + 1;
	return countT;
}

int main() {
	int n;
	int s, m, l, xl, xxl, xxxl;
	int t, p, eachP = 0;

	cin >> n;
	cin >> s >> m >> l >> xl >> xxl >> xxxl;
	cin >> t >> p;
	
	int countT = getCount(s, t) + getCount(m, t) + getCount(l, t) + getCount(xl, t) + getCount(xxl, t) + getCount(xxxl, t);
	int countP = 0;
	if (n % p == 0) countP = n / p;
	else if (n % p != 0) {
		countP = n / p;
		eachP = n % p;
	}

	cout << countT << endl;
	cout << countP << " " << eachP << endl;
}