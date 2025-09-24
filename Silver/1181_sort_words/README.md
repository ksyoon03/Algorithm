# 1181번 단어 정렬

N개의 단어를 입력 받아 아래와 같은 조건으로 정렬하는 프로그램 문제이다.

1. 길이가 짧은 것부터
2. 길이가 같으면 사전 순으로

단, 중복된 단어는 하나만 남기고 제거해야 한다.

해당 문제는 vector와 algorithm을 활용할 수 있으면 쉽게 풀 수 있는 문제다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool custom(const string a, const string b) {
	if (a.length() == b.length()) {
		return a < b;			// 사전순으로 정렬
	}
	return a.length() < b.length();		// 길이 순으로 정렬
}

int main() {
	int N;
	cin >> N;
	vector <string> words(N);
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	sort(words.begin(), words.end(), custom);
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());

	for (auto tmp : words) {
		cout << tmp << endl;
	}
}
```

```cpp
bool custom(const string a, const string b) {
	if (a.length() == b.length()) {
		return a < b;			// 사전순으로 정렬
	}
	return a.length() < b.length();		// 길이 순으로 정렬
}
```

custom 함수는 words를 차례로 입력 받아서 정렬 시키는 함수이다.

단어의 길이가 같으면 사전순으로, 단어의 길이가 다르면 길이가 짧은 순으로 정렬한다.

```cpp
sort(words.begin(), words.end(), custom);
```

sort 함수는 words 배열을 정렬하는 함수이다.

custom 함수를 쓰지 않으면 사전순으로 정렬을 기본으로 한다.

```cpp
auto it = unique(words.begin(), words.end());
```

자료형 auto는 상황에 알맞는 자료형을 자동으로 적용 시킨다. 단, 너무 많이 쓰면 가독성이 떨어진다.

unique 함수는 배열 내에서 겹치는 요소를 배열의 뒤로 밀어내는 역할을 한다. 이때, it에는 중복되어 밀려난 가장 첫 요소를 가리킨다.

```cpp
animals = { monkey, cat, cat, dog };
auto it = unique(animals.begin(), animals.end());
```

예를 들어 위와 같이 코드가 작성 되었다면 배열 animals의 순서는

monkey, cat, dog, cat으로 바뀌고, it은 두 번째 cat의 인덱스인 animals[4]가 저장된다.

```cpp
words.erase(it, words.end());
```

erase 함수는 it이 가리키는 인덱스부터 배열의 마지막 인덱스까지를 제거하여, vector의 실제 크기를 줄인다.

```cpp
for (auto tmp : words) {
		cout << tmp << endl;
	}
```

이런 식으로 for문을 작성하면 간단하게 vector의 모든 요소를 출력할 수 있다.
