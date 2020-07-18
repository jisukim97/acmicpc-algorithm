#include<iostream>

using namespace std;

bool checkHanSu(int n, int k){
	int* a = new int[k];
	int temp = n, prev, gap;

	for (int i = 0; i < k; i++) {
		a[i] = temp % 10;
		temp /= 10;
	}

	prev = a[0]; gap = a[1] - a[0];
	for (int i = 1; i < (k-1); i++) 
		if ((a[i + 1] - a[i]) != gap) return false;

	return true;
}

int main() {

	int n,k;
	cin >> n;
	int cnt=0;

	if (n < 100) cnt = n;
	else {
		cnt = 99;
		k = 3;

		for (int i = 100; i <= n; i++) {
			if (i == 1000) k = 4;
			if (checkHanSu(i, k)) cnt++; 
		}
	}
	
	cout << cnt;

	return 0;
}