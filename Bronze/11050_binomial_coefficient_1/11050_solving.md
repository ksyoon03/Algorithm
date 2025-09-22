# 11050번 이항계수

숫자 N과 K가 주어졌을 때 두 수의 이항계수를 구하는 문제이다.

<img width="209" height="75" alt="Image" src="https://github.com/user-attachments/assets/acb10641-57d4-4838-92f7-758dd2ce638d" />

이항계수의 공식을 알고, 이를 활용하는 함수를 만들면 쉽게 풀 수 있는 문제이다.

```cpp
#include <iostream>
using namespace std;

int fac(int num) {  // 팩토리얼 함수
	int res = 1;
	for (int i = 2; i <= num; i++) {
		res *= i;
	}
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	int res = fac(n) / (fac(k) * fac(n - k));
	cout << res << endl;
}
```
