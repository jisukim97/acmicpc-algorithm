#include<iostream>
#include<algorithm>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

int n,m;
int* arr;

bool binary_search(int low, int high, int num) {
	if (low > high) return false;
	else {
		int mid = (low + high) / 2;
		if (arr[mid] > num) return binary_search(low, (mid - 1), num);
		else if (arr[mid] == num) return true;
		else if (arr[mid] < num) return binary_search((mid + 1), high, num);
	}
}

int main() {
	
	scanf("%d", &n);
	arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	scanf("%d", &m);
	int high = n - 1, low = 0;
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		int ans = binary_search(low,high,tmp);
		if (ans) printf("1\n");
		else printf("0\n");
	}

	return 0;
}