# 4153번 직각삼각형

삼각형의 세 변을 입력 받고, 직각삼각형인지 아닌지를 판별하는 문제이다.

해당 문제는 sort() 함수를 이용하면 쉽게 풀 수 있다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> s(3);
	while (true) {
		cin >> s[0] >> s[1] >> s[2];
		if (s[0] == 0 && s[1] == 0 && s[2] == 0) return 0;

		sort(s.begin(), s.end());

		int a = s[0], b = s[1], c = s[2];

		if (a * a + b * b == c * c) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}
```

```cpp
sort(s.begin(), s.end());
```

입력 받은 값들을 오름차순으로 정렬하면

<aside>
💡

최소값 → 중간값 → 최대값

</aside>

위와 같이 정렬된다.

<aside>
💡

a^2 + b^2 = c^2  이므로

최소값^2 + 중간값^2 = 최대값^2

</aside>

위와 같이 공식이 맞다면 직각삼각형이고, 틀리면 직각삼각형이 아니다.