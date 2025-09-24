# 1764번 듣보잡

<aside>

### 문제

김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

</aside>

<aside>

### 입력

첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.

듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

</aside>

<aside>

### 출력

듣보잡의 수와 그 명단을 사전순으로 출력한다.

</aside>

이 문제는 단순히 배열끼리 비교하는 문제로 만들면 시간 초과가 발생하게 되어있다. 따라서 해당 문제는

이진 탐색을 활용하는 것이 좋다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;		// 듣잡의 수
	int m;	// 보잡의 수
	cin >> n >> m;
	
	vector <string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];  // 듣잡 입력
	}
	sort(v.begin(), v.end());  // 듣잡 정렬 (이진 탐색을 위해서)
	
	vector <string> result; // 듣보잡
	int count = 0;  // 듣보잡 수
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s; // 보잡 입력
		if (binary_search(v.begin(), v.end(), s)) {
		// 정렬한 듣잡 안에 보잡을 집어 넣어 이진 탐색한다.
			result.push_back(s);
			// 듣잡과 보잡이 일치하면 듣보잡 배열에 푸쉬
			count++; // 듣보잡의 수 + 1
		}
	}
	cout << count << endl; // 듣보잡 수
	sort(result.begin(), result.end()); // 사전순 정렬
	for (auto it : result) {
		cout << it << endl; // 듣보잡 출력
	}
}
```
