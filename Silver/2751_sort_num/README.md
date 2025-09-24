# 2751번 수 정렬하기 2

숫자 N을 입력받고, N만큼 수를 입력받는다.

입력받은 수들을 오름차순으로 정렬하고, 한 줄에 한 개씩 출력하는 문제이다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	for (int it : num) {
		cout << it << "\n";
	}
}
```

해당 문제는 sort 함수를 활용하면 매우 손쉽게 풀 수 있지만, 관건은 시간초과를 해결하는 것이다.

```cpp
cout << it << endl;    // 출력 후 버퍼를 비우는 작업을 수행한다.
cout << it << "\n";    // 단순 줄바꿈만 수행한다.
```

 처음에는 평소대로 endl을 사용하여 문제를 풀었는데, 자꾸 시간초과가 떠서 당황했었다.

 찾아보니 endl은 출력 후 버퍼(flush)를 비우는 작업을 수행하기 때문에

단순 줄바꿈을 수행하는 \n보다 훨씬 느려진다고 한다.

 출력할 수가 적으면 상관 없지만, 출력할 수가 많으면 endl 대신 \n을 사용하는 것이 시간을 훨씬 많이

아낄 수 있다.
