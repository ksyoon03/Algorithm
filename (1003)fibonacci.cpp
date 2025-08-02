#include <iostream>
using namespace std;

int zero_count[41];
int one_count[41];

void count() {
    zero_count[0] = 1;
    one_count[0] = 0;

    zero_count[1] = 0;
    one_count[1] = 1;

    for (int i = 2; i < 41; i++) {
        zero_count[i] = zero_count[i - 1] + zero_count[i - 2];
        one_count[i] = one_count[i - 1] + one_count[i - 2];
    }
}

int main() {
    int t;
    cin >> t;
    count();

    int* n = new int[t];
    for (int i = 0; i < t; i++) {
        cin >> n[i];
    }

    for (int i = 0; i < t; i++) {
        cout << zero_count[n[i]] << " " << one_count[n[i]] << endl;
    }
}