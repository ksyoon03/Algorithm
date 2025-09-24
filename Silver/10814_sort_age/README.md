# 10814번 나이순 정렬

N명의 사이트 가입자들의 나이와 이름이 주어진다. 가입자들을 나이 순으로 정렬하고, 나이가 같으면

먼저 가입한 순(입력순)으로 정렬하는 프로그램을 만드는 문제이다.

해당 문제는 utility 헤더파일에 들어있는 pair 클래스와 algorithm 헤더파일에 들어있는 sort 함수를

이용하면 쉽게 풀 수 있다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(const pair<int, string> a, const pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int n;
	int age;
	string name;
	cin >> n;
	vector<pair<int, string>> id;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		id.push_back({ age,name });
	}
	stable_sort(id.begin(), id.end(), compare);

	for (auto it : id) {
		cout << it.first << " " << it.second << "\n";
	}
}
```

```cpp
vector<pair<int, string>> id;
```

pair 클래스 id를 vector와 함께 사용했다. vector 배열에 id의 요소들이 저장된다.

```cpp
id.push_back({ age,name });
```

vector 배열에 요소를 저장하는 것이기 때문에 배열임을 분명히 해야한다.

```cpp
bool compare(const pair<int, string> a, const pair<int, string> b) {
	return a.first < b.first;
}
```

id를 그냥 정렬시키면 나이 순으로 정렬함과 동시에 이름도 알파벳 순으로 정렬하기 때문에 오답이 된다.

때문에 첫 번째 요소(나이)만 정렬 시키는 임의의 bool 함수 compare를 생성하여 정렬의 기준을 만들었다.

```cpp

sort(id.begin(), id.end(), compare);    // 불안정 정렬 발생
```

여기가 가장 중요한데, 이 문제는 sort 함수를 사용하면 오답이 된다.

sort 함수는 연산이 빠르고, 효율적인 대신 안정성이 떨어진다.

때문에 아래와 같이 sort 함수는 불안정 정렬이 일어날 수 있다.

<aside>

20 민수 → 21 아영 → 20 준수    (좌측부터 입력)

20 준수 → 20 민수 → 21 아영    (이름이 입력순으로 정렬되지 않음)

</aside>

```cpp

stable_sort(id.begin(), id.end(), compare);    // 안정 정렬
```

위와 같이 stable_sort 함수를 사용하여 안정 정렬을 해주면 문제를 해결할 수 있다.
