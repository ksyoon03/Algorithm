# 10818번 최소, 최대

숫자 N을 입력 받고, N개의 정수를 입력받은 후 정수들 중 최댓값과 최소값을 출력하는 문제이다.

해당 문제는 배열과 최대, 최소값을 찾는 반복문을 활용하면 쉽게 풀 수 있다.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int max = num[0];
	int min = num[0];
	for (int i = 0; i < num.size(); i++) {
		if (max <= num[i]) max = num[i];
		if (min >= num[i]) min = num[i];
	}
	cout << min << " " << max << endl;
}
```