# 1920번 수 찾기

N개의 정수 A[1], A[2], …, A[N]이 주어지고, M개의 정수 B[1], B[2], …, B[M]이 주어질 때 A 배열에 B 배열의 요소가 들어 있는지 확인하는 프로그램을 작성하는 문제이다.

들어 있다면 1을, 없다면 0을 출력하면 된다.

해당 문제는 algorithm 헤더 파일에 들어있는 binary_search() 함수를 사용하면 쉽게 풀 수 있다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	cin >> m;
	vector <int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < b.size(); i++) {
	// 찾는 값이 b 배열의 값이므로 배열 b를 기준으로 반복을 실행한다.
		if (binary_search(a.begin(), a.end(), b[i])) {
			cout << 1 << "\n"; // 빠른 처리를 위해서 endl 대신 \n을 사용하는 것이 좋다.
		}                    // endl 사용시 백준에서는 시간 초과가 발생한다.
		else cout << 0 << "\n";
	}
}
```

<aside>
💡

### 이진 탐색(binary_search)의 원리

1. **중간 값 확인**: 먼저 전체 데이터의 정중앙에 있는 값과 찾고자 하는 값을 비교한다.
2. **범위를 절반으로 줄이기**
    - 찾는 값이 중간 값보다 작으면, 중간 값의 왼쪽 절반만 탐색한다.
    - 찾는 값이 중간 값보다 크면, 중간 값의 오른쪽 절반만 탐색한다.
3. **반복**: 이 과정을 찾고자 하는 값을 찾거나 더 이상 탐색할 데이터가 없을 때까지
    
    반복한다.
    
</aside>

위와 같은 원리를 이용하기 위해서 우선 아래와 같이 배열 A를 오름차순으로 정렬해준다.

```cpp
sort(a.begin(), a.end());
```

```cpp
if (binary_search(a.begin(), a.end(), b[i])) {
// binary_search(시작 인덱스, 끝 인덱스, 찾고자 하는 값)
			cout << 1 << "\n";
		}
		else cout << 0 << "\n";
```

그 후에는 위와 같이 binary_search 함수를 이용하면 된다.

( binary_search 함수는 bool 함수이다.)