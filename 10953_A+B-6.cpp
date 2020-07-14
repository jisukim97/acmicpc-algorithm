#include<iostream>

using namespace std;


int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << (s[0] - '0') + (s[2] - '0')<<"\n";
	}

	return 0;
}