#include<iostream>

using namespace std;

int main() {

	while (1) {
		string s;
		cin >> s;

		if (s == "0")break;

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

		if (flag) cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}