#include<iostream>
#include<cmath>

using namespace std;

int main() {
	string s;
	cin >> s;

	int tot = 0;
	int exp = 0;
	int slen = s.size();
	for (int i = slen-1; i >= 0; i--, exp++) {
		if (s[i] >= 65) tot += (s[i] - 55)*pow(16,exp);
		else tot += (s[i] - '0') * pow(16, exp);
	}

	cout << tot;

	return 0;
}