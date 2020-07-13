#include<iostream>

using namespace std;

int main() {

	int *a = new int[5];
	int total = 0;

	for (int i = 0; i < 5; i++)
		cin >> a[i];

	for (int i = 0; i < 5; i++)
		if (a[i] >= 40) total += a[i];
		else total += 40;

	cout << total/5;
	return 0;
}