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
				if (vps.top() == '(' && str[j] == ')') {	// 스택의 가장 위에 있는 요소가 '(' 이고, 문자열의 j번째 괄호가 ')' 이면
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