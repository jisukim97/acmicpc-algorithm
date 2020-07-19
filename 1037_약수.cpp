#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	if (n == 1) cout << a[0] * a[0];
	else cout << a[0] * a[n - 1];

	return 0;
}