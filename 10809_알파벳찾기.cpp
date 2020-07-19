#include<iostream>
using namespace std;

int main() {

	string s;
	cin >> s;
	
	int* a = new int[26];

	for (int i = 0; i < 26; i++) {
		if (s.find(i + 97) < s.size()) a[i] = s.find(i + 97);
		else a[i] = -1;
	}

	for (int i = 0; i < 26; i++) {
		cout << a[i];
		if (i == 25) break;
		cout << " ";
	}

	return 0;
}