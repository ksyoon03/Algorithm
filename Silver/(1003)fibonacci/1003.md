# 1003번 피보나치 함수

<aside>

### 문제

다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

```cpp
int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}

```

`fibonacci(3)`을 호출하면 다음과 같은 일이 일어난다.

- `fibonacci(3)`은 `fibonacci(2)`와 `fibonacci(1)` (첫 번째 호출)을 호출한다.
- `fibonacci(2)`는 `fibonacci(1)` (두 번째 호출)과 `fibonacci(0)`을 호출한다.
- 두 번째 호출한 `fibonacci(1)`은 1을 출력하고 1을 리턴한다.
- `fibonacci(0)`은 0을 출력하고, 0을 리턴한다.
- `fibonacci(2)`는 `fibonacci(1)`과 `fibonacci(0)`의 결과를 얻고, 1을 리턴한다.
- 첫 번째 호출한 `fibonacci(1)`은 1을 출력하고, 1을 리턴한다.
- `fibonacci(3)`은 `fibonacci(2)`와 `fibonacci(1)`의 결과를 얻고, 2를 리턴한다.

1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, `fibonacci(N)`을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

</aside>

<aside>

### 입력

첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

</aside>

<aside>

### 출력

각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

</aside>

이 문제는 피보나치 수열을 활용하여 0과 1이 출력되는 횟수를 구하는 문제이다.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int cnt0 = 0;      // 0의 개수
int cnt1 = 0;      // 1의 개수

int fib(int n) {    // 피보나치 함수
    if (n == 0) {   // n이 0이면
        cnt0++;     // 0의 개수 + 1
        return 0;   // 0 반환
    }
    else if (n == 1) {  // n이 1이면
        cnt1++;     // 1의 개수 + 1
        return 1;   // 1 반환
    }
    else {
        return fib(n - 1) + fib(n - 2);
        // n이 0 또는 1이 아니면
        // n이 0이 될 때까지 함수 반복
    }
}

int main() {
	int t;  // 테스트 케이스 개수
	cin >> t;
    vector <int> v(t);  // 입력받을 수

	for (int i = 0; i < t; i++) {
        cin >> v[i];
        fib(v[i]); // 입력받은 수로 피보나치 함수 호출
        cout << cnt0 << " " << cnt1 << endl;
        cnt0 = 0;
        cnt1 = 0;
	}
}
```

처음에는 위와 같이 문제를 풀었으나, fib(4)와 같이 호출할 경우에는 fib(2)와 같은 함수들이 여러 번 중복 호출된다. 이렇게 되면 연산량이 과도하게 늘어나서 시간 초과가 발생한다.

그 때문에 아래와 같이 풀어주면 된다.

```cpp
#include <iostream>
#include <vector>
#include <utility> // pair를 쓰기 위한 헤더파일
using namespace std;

int main() {
	int t;
	cin >> t;

	vector <pair <int, int>> dp(41);
	// n의 크기는 40 이하
	// { 0의 개수, 1의 개수 }

	dp[0] = { 1, 0 };		// 0번째 수열
	dp[1] = { 0, 1 };		// 1번째 수열

	for (int i = 2; i <= 40; i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;		// i번째 수열에서 0의 개수
		dp[i].second = dp[i - 1].second + dp[i - 2].second;	// i번째 수열에서 1의 개수
	}

	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n].first << " " << dp[n].second << endl;	// n번째 수열의 0의 개수와 1의 개수 출력
	}
}
```

위의 코드는 동적 계획법이라는 방법을 활용하여 풀었다.

<aside>

- **동적 계획법**이란?
    - 미리 계산했던 값을 저장해두고, 나중에 필요할 때 불러오는 방법
</aside>

피보나치 수열의 경우에는 dp[n]에 n번쨰 수열이 호출될 때, 0과 1이 몇 번 호출되는지 저장하면 된다.

```cpp
vector <pair <int, int>> dp(41);

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };
```

dp[n]을 pair<int, int>로 만들어서, ( 0 호출 횟수, 1 호출 횟수)를 저장한다.

```cpp
for (int i = 2; i <= 40; i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
```

앞서 0번째와 1번째 수열은 초기화를 했기 때문에 2번째 수열부터 반복을 실행하면 된다.

```cpp
dp[i] = dp[i - 1] + dp[i - 2] 이므로
```

```cpp
dp[i].first = dp[i - 1].first + dp[i - 2].first
```

```cpp
dp[i].second = dp[i - 1].second + dp[i - 2].second 이다.
```

이와 같이 코드를 만들면 n번째 수열에서 몇 개의 0과 1이 호출되었는지 미리 저장되어있기 떄문에, 중복 연산이 일어나지 않아, 프로그램이 빠르게 실행된다.
