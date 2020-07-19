#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int cnt = 0;
	int flag = 1;
	int block;
	string * s = new string[8];

	for (int i = 0; i < 8; i++)
		cin >> s[i];

	for (int i = 0; i < 8; i++) {
		if (i % 2 != 0) flag = 0;
		else flag = 1;
		for (int j = 0; j < 8; j++) {
			block = (int)s[i][j];
			if (flag && block == 70) cnt++; 
			flag = !flag;
		}
	}

	cout << cnt;

	return 0;
}