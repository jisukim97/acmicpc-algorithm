#include<iostream>

using namespace std;


int main() {

	int x,n;
	cin >> n >> x;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		if (a[i]< x) cout << a[i]<<" ";

	return 0;
}