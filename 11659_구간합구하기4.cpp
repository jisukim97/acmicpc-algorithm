#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;


int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int prefix_sum=0;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		prefix_sum += tmp;
		arr[i] = prefix_sum;
	}

	for (int i = 0; i < m; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		int result = (start-1)? arr[end-1] - arr[start - 2] : arr[end-1];
		printf("%d\n", result);
	}

	return 0;
}