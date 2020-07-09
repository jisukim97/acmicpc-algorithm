#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int* a;
	int n, small;
	cin >> n;

	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a, a + n);

	for (int i = 0; i < n; i++)
		cout << a[i] <<"\n";


	delete[] a;
	return 0;
}