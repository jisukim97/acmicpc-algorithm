#include<iostream>

using namespace std;

int fact(int n) {
	if (n == 0) return 1;
	else if (n <= 2) return n;
	else return fact(n - 1)*n;
}

int main() {

	int n;
	cin >> n;

	int result = fact(n);

	cout << result;
	return 0;
}
