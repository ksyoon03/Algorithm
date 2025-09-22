# 9012번 괄호

<aside>

괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.

</aside>

이 문제는 처음에 vector와 algorithm을 활용해 풀어보려고 했다. 그러나 잘 되지 않아서 다른 방법을 찾아보니 stack을 활용하면 쉽게 풀 수 있다는 것을 알았다. 애초에 이 문제는 stack을 연습하라고 만들어진 문제인 것 같다.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		stack <char> vps;		// 스택 초기화
		string str;		// 괄호 문자열
		cin >> str;
		for (int j = 0; j < str.length(); j++) {	// 문자열의 길이만큼 반복
			if (vps.empty()) {	// 스택이 비어있으면
				vps.push(str[j]);		// j번째 괄호 푸쉬
			}
			else {
				if (vps.top() == '(' && str[j] == ')') {
				// 스택의 가장 위에 있는 요소가 '(' 이고, 문자열의 j번째 괄호가 ')' 이면
					vps.pop();		// 스택의 가장 위에 있는 요소 제거
				}
				else {	// 하나라도 아니면
					vps.push(str[j]);		// 스택에 문자열의 j번째 괄호 푸쉬
				}
			}
		}
		if (vps.empty()) cout << "YES" << endl;	// 스택의 최종값이 비어있으면 YES
		else cout << "NO" << endl;		// 아니면 NO
	}
}
```