#include <iostream>
#include <queue>	// vector ���� ����� ����
using namespace std;

int main() {
	int N;
	cin >> N;
	queue <int> num;
	for (int i = 1; i <= N; i++) {
		num.push(i);		// 1���� N���� ������� ����
	}
	
	while (num.size() > 1) {		// ť�� ũ�Ⱑ 1���� Ŭ ���ȸ� �ݺ�
		num.pop();	// ť�� ù ��° ��� ����
		num.push(num.front());		// ť�� ù��° ��Ҹ� ������ ��ҷ� �߰�
		num.pop();		// ���� ù ��° ��Ҵ� ����
	}
	cout << num.front() << endl;
}