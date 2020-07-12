#include<iostream>

using namespace std;


int main() {

	int a;
	cin >> a;

	for (int i = 1; i <= a; i++) {
		for (int j = a; j > i; j--) cout << " ";
		for (int j = 1; j <= i; j++)
			cout << "*";
		if (i == a) break;
		cout << "\n";
	}

	return 0;
}