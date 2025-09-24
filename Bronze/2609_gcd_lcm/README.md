# 2609번 최대공약수, 최소공배수

말 그대로 최대공약수와 최소공배수를 구하는 문제이다.

이 문제는 간단한 공식만 알고 있으면 쉽게 풀 수 있다.

### 유클리드 호제법 (유클리드 알고리즘)

- 두 자연수 a, b에 대해 (a>b) a를 b로 나눈 나머지를 r이라 하면, a와 b의 최대공약수는 b와 r의 최대공약수와 동일하다.
    
    
    b를 r로 나눈 나머지 r’을 구하고, 다시 r을 r’로 나눈 나머지를 구하는 과정을 반복해 나머지가 0이 되었을 때 나누는 수와 a와 b의 최대공약수
    

```cpp
int gcd(int a, int b) {
		while (b) {       // b가 0이 될 때까지 반복한다.
			int temp = b;   // temp에 b의 현재 값을 저장한다.
			b = a % b;      // b에는 a를 b로 나눈 나머지 값을 저장한다.
			a = temp;       // a에는 temp의 현재 값을 저장한다.
		}
		return a;         // a를 반환한다.
}
```

### 최소공배수

최소 공배수는 a와 b의 곱을 두 수의 최대공약수로 나누면 구할 수 있다.

```cpp
int lcm = a * b / gcd(a, b)
```

이를 토대로 한 코드는 아래와 같다.

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;

	if (a >= b) {
		while (b) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	if (b > a) {
		while (a) {
			int temp = a;
			a = b % a;
			b = temp;
		}
		return b;
	}
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
}
```
