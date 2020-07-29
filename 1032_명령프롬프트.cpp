#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s; //기준이 되는 첫번째 파일이름을 넣는다
	int s_len = s.size();

	for (int i = 1; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < s_len; j++) 
			if (s[j] != tmp[j]) s[j] = '?';
	}

	cout << s;

	return 0;
}