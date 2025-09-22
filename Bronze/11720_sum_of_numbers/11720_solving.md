# 11720번 숫자의 합

숫자 N을 입력받고, N개의 숫자를 공백 없이 입력 받아 합을 구하는 문제이다.

해당 문제는 공백 없이 입력을 받기 때문에 string형으로 입력을 받고, 아스키 코드를 활용해서 푸는 것이 좋다.

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	string num;
	cin >> n >> num;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i] - '0';
	}
	cout << sum << endl;
}
```

<aside>
💡

</aside>