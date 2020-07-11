#include<iostream>
#include<string>

using namespace std;


int main() {

	int cnt=0, flag=1; //공백 등장하면 1으로
	string s;
	getline(cin,s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 32) flag = 1;
		else if (flag) {
			cnt++;
			flag = 0;
		}
	}

	cout << cnt;

	return 0;
}