#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int* rest = new int[10];

	for (int i = 0; i < 10; i++) {
		int tmp;
		cin >> tmp;

		rest[i] = tmp % 42;
	}

	sort(rest, rest + 10);

	int cnt = 1;
	int rest_now = rest[0];

	for (int i = 1; i < 10; i++) {
		if (rest_now != rest[i]) {
			cnt++;
			rest_now = rest[i];
		}
	}

	cout << cnt;

	return 0;
}