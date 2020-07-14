#include<iostream>
#include<string>

using namespace std;


int main() {
	string s;
	cin >> s;
	int cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c <= 67) cnt += 3;
		else if (c <= 70) cnt += 4;
		else if (c <= 73) cnt += 5;
		else if (c <= 76) cnt += 6;
		else if (c <= 79) cnt += 7;
		else if (c <= 83) cnt += 8;
		else if (c <= 86) cnt += 9;
		else if (c <= 90) cnt += 10;
	}
	
	cout << cnt;

	return 0;
}