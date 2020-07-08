#include<iostream>
using namespace std;

int main() {

	long long a, b;
	cin >> a >> b;
	long long result;

	if (a > b) result = a - b;
	else result = b - a;

	if (result >= 0) cout << result;
	else cout << -result;


	return 0;
}