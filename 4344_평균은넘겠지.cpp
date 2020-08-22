#include<iostream>
#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		int* arr = new int[num];
		int sum = 0;
		for (int j = 0; j < num; j++) {
			int tmp;
			scanf("%d", &tmp);
			arr[j] = tmp;
			sum += tmp;
		}
		sort(arr, arr + num, cmp);
		double mean = (double)sum / num;
		int cnt = 0;
		for (int j = 0; j < num; j++) {
			if (arr[j] > mean) cnt++;
			else break;
		}
		double result = (double)cnt / num * 100;
		printf("%.3lf%%\n", result);
	}

	return 0;
}