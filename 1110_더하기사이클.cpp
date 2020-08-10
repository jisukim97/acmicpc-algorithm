#include<iostream>
#include<sstream>

using namespace std;

int main() {
	
	string org_n;
	cin >> org_n;

	string tmp_n = org_n;
	int ten, one; //십의 자리, 일의 자리를 지칭
	int cnt = 0;
	
	while (1) {
		if (tmp_n.size() < 2)
		{
			ten = 0;
			one = tmp_n[0] - '0';
		}
		else {
			ten = tmp_n[0] - '0';
			one = tmp_n[1] - '0';
		}

		int sum = ten + one;
		int tmp = one * 10 + (sum % 10); 
		
		stringstream ss;
		ss << tmp;
		tmp_n = ss.str();

		cnt++;

		if (tmp_n == org_n) break;
	}

	cout << cnt;

	return 0;
}