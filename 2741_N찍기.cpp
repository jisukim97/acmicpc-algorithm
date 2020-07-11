#include<iostream>
using namespace std;



int main() {

	int a, sum=0;
	cin >> a;

	for (int i = 1; i <= a; i++) {
		cout << i;
		if (i == a) break;
		cout << "\n";
	}

	return 0;
}