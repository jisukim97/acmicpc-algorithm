#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int main() {

	string a, b;
	cin >> a >> b;
	int A, B;
	A = (a[0] - '0') + (a[1] - '0') * 10 + (a[2] - '0') * 100;
	B = (b[0] - '0') + (b[1] - '0') * 10 + (b[2] - '0') * 100;

	if (A > B) cout << A;
	else cout << B;

	return 0;
}