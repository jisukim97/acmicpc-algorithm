#include<iostream>

using namespace std;

int main() {

	string s;
	cin >> s;

	int flag = 0; //false면 1로
	int slen = s.size();
	int half_index = slen / 2;

	for (int i = 0; i < half_index; i++) {
		int back = slen - i - 1;
		if (s[i] != s[back]) {
			flag = 1;
			break;
		}
	}

	if (flag) cout<<  0;
	else cout<< 1;

	return 0;
}