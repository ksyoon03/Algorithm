# 1259번 팰린드롬수

팰린드롬수란 12321과 같이 앞으로 쓰나, 뒤로 쓰나 같은 수를 말한다.

입력 받은 수가 팰린드롬수인지 아닌지를 구별하는 프로그램을 만드는 문제이다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		string num;
		cin >> num;
		if (num == "0") return 0;

		string re_num = num;
		reverse(re_num.begin(), re_num.end());
		if (num == re_num) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
```

```cpp
#include <algorithm>
reverse(re_num.begin(), re_num.end());
```

C++에서는 algorithm 헤더파일 내에 vector나 string을 뒤집을 수 있는 reverse 함수가 존재하기 때문에

이를 이용하면 아주 쉽게 문제를 해결할 수 있다.