#include <iostream>
#include <string>
using namespace std;

int main() {
	string words;
	int count = 1;
	getline(cin, words);

	for (int i = 0; i < words.length(); i++) {
		if (words[i] == ' ') {
			count++;
		}
	}
	if (words[0] == ' ') {
		count--;
	}
	if (words[words.length() - 1] == ' ') {
		count--;
	}

	cout << count << endl;
}
