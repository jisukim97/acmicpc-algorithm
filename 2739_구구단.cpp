#include<iostream>

using namespace std;

int main() {

	int a;
	cin >> a;

	for (int i = 1; i <= 9; i++) {
		cout << a << " * " << i << " = " << a * i;
		if (i == 9) break;
		cout << "\n";
	}
	return 0;
}