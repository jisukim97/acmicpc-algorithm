#include<iostream>

using namespace std;

int main() {


	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		for (int j = 2; j <= num; j++) {
			if (num == j) cnt++;
			if (num % j == 0) break;
		}
	}

	cout << cnt;

	return 0;
}
