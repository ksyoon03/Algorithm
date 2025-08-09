#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		stack <char> vps;		// ���� �ʱ�ȭ
		string str;		// ��ȣ ���ڿ�
		cin >> str;
		for (int j = 0; j < str.length(); j++) {	// ���ڿ��� ���̸�ŭ �ݺ�
			if (vps.empty()) {	// ������ ���������
				vps.push(str[j]);		// j��° ��ȣ Ǫ��
			}
			else {
				if (vps.top() == '(' && str[j] == ')') {	// ������ ���� ���� �ִ� ��Ұ� '(' �̰�, ���ڿ��� j��° ��ȣ�� ')' �̸�
					vps.pop();		// ������ ���� ���� �ִ� ��� ����
				}
				else {	// �ϳ��� �ƴϸ�
					vps.push(str[j]);		// ���ÿ� ���ڿ��� j��° ��ȣ Ǫ��
				}
			}
		}
		if (vps.empty()) cout << "YES" << endl;	// ������ �������� ��������� YES
		else cout << "NO" << endl;		// �ƴϸ� NO
	}
}