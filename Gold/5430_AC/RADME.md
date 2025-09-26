# 5430번 AC

<aside>

## 문제

---

선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.

함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

</aside>

<aside>

## 입력

첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.

각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.

다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)

다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)

전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

</aside>

<aside>

## 출력

각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.

</aside>

이 문제는 `deque`를 활용해서 풀면 좀 더 쉽게 풀 수 있는 문제이다.

그렇지만 개인적으로는 어렵게 느껴진 문제이기도 하다.

`deque`를 활용하면 `vector`나 다른 자료구조와 다르게 `reverse()`와 같은 함수를 사용해서 배열을 일일히 뒤집는 과정을 거치지 않아도 되기 때문에 런타임을 줄일 수 있다.

```cpp
#include <cctype> // isdigit() 함수를 위해 필요

deque <int> p;
string tmp = "";

for (char c : arr) {
	if (isdigit(c)) {
		tmp += c;
	}
	else {
		if (tmp != "") {
			p.push_back(stoi(tmp));
			tmp = "";
		}
	}
}
```

위와 같이 `isdigit()` 함수를 사용하면 배열에서 문자와 숫자를 구별하는 것이 가능하다.

(숫자면 `true`, 아니면 `false`를 반환한다.)

다음은 아래와 같은 과정을 거친다.

1. **반복을 시작하기 전**에 공백이 저장된 `string` 변수 `tmp`를 생성한다.
2. 배열의 요소가 숫자이면 `tmp`에 더한다.
3. `tmp`가 공백이 아니면 `stoi(tmp)`를 사용하여 `tmp`의 값을 정수형으로 바꾼 후 덱에 푸쉬한다.
4. `tmp`는 다시 공백으로 초기화한다.
5. 입력 받은 **배열의 크기**만큼 반복한다.

위 과정을 거친 후에는 덱에 숫자만 저장 되어있다.

```cpp
bool rev = false;
bool err = false;

for (int i = 0; i < com.size(); i++) {
	if (com[i] == 'R') {
		rev = !rev;
	}
	else if (com[i] == 'D') {
		if (p.empty()) {
			err = true; 
			break;
		}
		if (rev) {
			p.pop_back();
		}
		else {
			p.pop_front();
		}
	}
}
```

함수 커맨드를 수행하는 코드의 로직은 아래와 같다.

- `bool형` 변수인 `rev`(배열 뒤집기)와 `err`(에러 출력)를 생성한다.

```cpp
bool rev = false;
bool err = false;
```

- `for (int i = 0; i < com.size(); i++)`:
    - 입력받은 함수 커맨드의 수만큼 반복을 실행한다.

```cpp
for (int i = 0; i < com.size(); i++) {
	. . .
}
```

- `if (com[i] == 'R')`: 커맨드가 `R`일 때
    - `rev`변수가 `true`면 `false`, `false`면 `true`를 저장한다.

```cpp
if (com[i] == 'R') {
		rev = !rev;
	}
```

- `else if (com[i] == 'D')`: 커맨드가 `D`일 때
    - 덱이 비어있다면
        - `err`변수를 `true`로 바꾸고 반복문 종료
    - `rev` 변수가 `true`라면 배열을 뒤집은 것이므로
        - 덱에서 `pop_back`
    - `rev` 변수가 `false`라면 배열이 뒤집히지 않은 것이므로
        - 덱에서 `pop_front`
    
    ```cpp
    else if (com[i] == 'D') {
    		if (p.empty()) {
    			err = true; 
    			break;
    		}
    		if (rev) {
    			p.pop_back();
    		}
    		else {
    			p.pop_front();
    		}
    	}
    ```
    

```cpp
	if (err) {
		cout << "error" << endl;
	}
	else {
		cout << "[";
		if (!p.empty()) {
			if (rev) {
				while (p.size() > 1) {
					cout << p.back() << ",";
					p.pop_back();
				}
				cout << p.back();
			}
			else {
				while (p.size() > 1) {
					cout << p.front() << ",";
					p.pop_front();
				}
				cout << p.front();
			}
		}
		cout << "]" << endl;
	}
}
```

덱의 내용을 출력하는 코드의 로직은 다음과 같다.

- `err` 변수가 `true`라면 **error** 출력 후 현재 진행 중인 반복 종료
    
    ```cpp
    if (err) {
    	cout << "error" << endl;
    }
    ```
    

- `else { … }` : `err` 변수가 `false` 일 때,
- `if (!p.empty())` : 덱이 비어있지 않다면
    
    ```cpp
    if (!p.empty()){
    . . .
    }
    ```
    
    <aside>
    
    ### ⚠️ `!p.empty()`를 해줘야 하는 이유!
    
    이유는 `err`변수가 `D 명령어`를 처리하는 구간에서만 `true`로 바뀌기 때문이다.
    
    만약 덱의 요소가 하나만 있을 때 `D 명령어`가 실행되면 요소는 제거되고, `err`변수는 `false`로
    
    남아있게 된다.
    
    `!p.empty()`를 넣어주지 않으면 이런 경우에 런타임 에러가 발생한다.
    
    </aside>
    

- `rev` 변수가 `true` 일 때 (배열의 순서가 뒤에서부터 일 때)
    - 덱의 크기가 1보다 클 때만 반복하면서 덱의 뒤에서부터 순서대로 출력 후 제거
    - 반복 종료 후에는 덱의 마지막 요소를 출력

```cpp
if (rev) {
		while (p.size() > 1) {
			cout << p.back() << ",";
			p.pop_back();
		}
		cout << p.back();
	}
```

- `rev` 변수가 `false` 일 때 (배열의 순서가 앞에서부터 일 때)
    - 덱의 크기가 1보다 클 때만 반복하면서 덱의 앞에서부터 순서대로 출력 후 제거
    - 반복 종료 후에는 덱의 마지막 요소를 출력
    
    ```cpp
    if (rev) {
    		while (p.size() > 1) {
    			cout << p.back() << ",";
    			p.pop_front();
    		}
    		cout << p.front();
    	}
    ```
    

위와 같이 코드를 작성하면 답을 확인할 수 있다.

```cpp
#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		string com, arr;

		cin >> com;
		cin >> n;
		cin >> arr;

		deque <int> p;
		string tmp = "";

		for (char c : arr) {
			if (isdigit(c)) {		
			// isdigit() : 문자가 숫자인지 아닌지 판별하는 함수
			// 숫자라면 true, 아니라면 false 반환
				tmp += c;
			}
			else {
				if (tmp != "") {
					p.push_back(stoi(tmp));
					tmp = "";
				}
			}
		}
		
		bool rev = false;
		bool err = false;

		for (int i = 0; i < com.size(); i++) {
			if (com[i] == 'R') {
				rev = !rev;
			}
			else if (com[i] == 'D') {
				if (p.empty()) {
					err = true; 
					break;
				}
				if (rev) {
					p.pop_back();
				}
				else {
					p.pop_front();
				}
			}
		}
		if (err) {
			cout << "error" << endl;
		}
		else {
			cout << "[";
			if (!p.empty()) {
				if (rev) {
					while (p.size() > 1) {
						cout << p.back() << ",";
						p.pop_back();
					}
					cout << p.back();
				}
				else {
					while (p.size() > 1) {
						cout << p.front() << ",";
						p.pop_front();
					}
					cout << p.front();
				}
			}
			cout << "]" << endl;
		}
	}
}
```
