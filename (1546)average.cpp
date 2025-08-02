#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <double> score(n);
	double max = score[0];
	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (max < score[i]) max = score[i];
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}

	cout << double(sum / n) << endl;
}