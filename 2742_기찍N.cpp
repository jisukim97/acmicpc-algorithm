#include<iostream>
using namespace std;



int main() {

	int a, sum=0;
	cin >> a;

	for (int i = a; i >= 1; i--) {
		cout << i;
		if (i == 1) break;
		cout << "\n";
	}

	return 0;
}